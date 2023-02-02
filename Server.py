
import socket

ser = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
ser.bind(("127.0.0.2", 5001))

ser.listen(1)
(cli, addr)= ser.accept()

while True:

    recibido = cli.recv(1024).decode()
    print("Recibo conexion de la IP: " + str(addr[0]) + " Puerto: " + str(addr[1]))
    print("Cliente: "+recibido)

cli.close()
ser.close()

print("Conexiones cerradas")
