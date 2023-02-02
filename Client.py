import socket
import time

host = '127.0.0.2'
port = 5001

obj = socket.socket()

obj.connect((host, port))
print("Conectado al servidor") 
while True:
    mens = input("Mensaje desde Cliente a Servidor >> ")

    obj.send(mens.encode())
    time.sleep(1)

obj.close()

print("Conexión cerrada")
