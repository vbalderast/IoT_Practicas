#! /usr/bin/python
import socket


def main():
    HOST = "127.0.0.112"
    PORT = 5001

    server_socket = socket.socket()
    server_socket.bind((HOST, PORT))

    server_socket.listen(2)
    conn, address = server_socket.accept()
    print("Connection to address: " + str(address))
    while True:
        data = conn.recv(1024).decode()
        if not data:
            break
        print("Client message: " + str(data))
        data = input('Server message: ')
        conn.send(data.encode())

    conn.close()


if _name_ == "_main_":
    main()