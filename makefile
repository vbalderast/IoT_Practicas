CC = gcc

all: server client

server: Server.c
	$(CC) Server.c -o server

client: Client.c
	$(CC) Cliente.c -o client

clean:
	rm -f server client

fresh:
	clean all