#!/usr/bin/env python
#Se importa el módulo
import socket

#instanciamos un objeto para trabajar con el socket
ser = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
#Puerto y servidor que debe escuchar
ser.bind(("192.168.1.98", 5001))

#Aceptamos conexiones entrantes con el metodo listen. Por parámetro las conexio>
ser.listen(1)
#Instanciamos un objeto cli (socket cliente) para recibir datos
cli, addr = ser.accept()

while True:

    #Recibimos el mensaje, con el metodo recv recibimos datos. Por parametro la>
    recibido = cli.recv(1024)

    #Si se reciben datos nos muestra la IP y el mensaje recibido
    print("Recibo conexion de la IP: " + str(addr[0]) + " Puerto: " + str(addr[>

    #Devolvemos el mensaje al cliente
    cli.send(recibido)


#Cerramos la instancia del socket cliente y servidor
cli.close()
ser.close()

print("Conexiones cerradas")
