const express = require('express')
const socketio = require('socket.io')
const path = require('path')
const http = require('http')
const serialport = require('serialport')
const colors = require('colors')

const app = express()
const server = http.createServer(app)

const io = socketio.listen(server)

/*rutas estaticas */
app.use('/chartjs',express.static('node_modules/chart.js'))
app.use('/bootstrap', express.static('node_modules/bootstrap'))
app.use('/jquery', express.static('node_modules/jquery/dist'))
app.use('/public',express.static('public'))

/**/

io.on('connection',(socket)=>{
    console.log('server> '.yellow + 'socket conexion ' +  colors.red('OK'))
})

app.get('/',(req,res,next)=>{
    res.sendFile(__dirname + '/index.html')
})

/**Configuracion de Puerto Serial */
const ReadLine = serialport.parsers.Readline

const parser = new ReadLine() //{ delimiter: '\r\n' }

const port = new serialport('COM14',{ 
    baudRate: 9600
    
})

const Parse = port.pipe(parser)


//activo puerto serie
//capturo el dato que viene por el puerto serie
port.on('open',()=>{
    console.log('server> '.yellow + 'Serial Port ' + colors.red('OPEN'))
}) 

Parse.on('data', (data)=>{
   // console.log('server> '.yellow + 'Serial Port ' + colors.red(data.toString()))
   // data = data.toString()
     data =  JSON.parse(data.toString())

    io.emit('arduino:data', {
        value: data
    })
})

port.on('err',(err)=>{
    console.log('server> '.yellow + colors.red(err))
})

server.listen('3000',() => {
    console.log('server> '.yellow + 'Server UP, puerto:' +  colors.red('3000'))
})
