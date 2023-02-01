#!/usr/bin/env python

#Variables
host = '192.168.1.98'
port = 5001
#Se importa el módulo
import socket
#Creación de un objeto socket (lado cliente)
obj = socket.socket()

#Conexión con el servidor. Parametros: IP (puede ser del tipo 192.168.1.1 o loc>
obj.connect((host, port))
print("Conectado al servidor")
#Creamos un bucle para retener la conexion
while True:
    #Instanciamos una entrada de datos para que el cliente pueda enviar mensajes
    mens = input("Mensaje desde Cliente a Servidor >> ")

    #Con el método send, enviamos el mensaje
    obj.send((mens))
#Cerramos la instancia del objeto servidor
obj.close()

#Imprimimos la palabra Adios para cuando se cierre la conexion
print("Conexión cerrada")

