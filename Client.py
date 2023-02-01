#! /usr/bin/python

import socket

def main():

    HOST = "127.0.0.112"
    PORT = 5001

    client_socket = socket.socket()
    client_socket.connect((HOST, PORT))

    message = input("Client message:")
    while message.lower().strip() != 'bye':
        client_socket.send(message.encode())
        data = client_socket.recv(1024).decode()

        print('Server: ' + data)
        message = input("Client message: ")

    client_socket.close()


if _name_ == "_main_":
    main()