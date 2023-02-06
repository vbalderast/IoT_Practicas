#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>
#include <fcntl.h>

#define BACKLOG 20 /* El numero de conexiones permitidas */
#define MAXDATASIZE 500000

main(int argc, char *argv[])
{
  int  PORT =5012; /* El puerto que serabierto */
  int numbytes;

//TIME VARIABLES
   time_t t = time(NULL);
   struct tm tm = *localtime(&t);

   char buf[MAXDATASIZE];
   int fd, fd2, fd3; /* los ficheros descriptores */

   struct sockaddr_in server;
   /* para la informaci de la direcci del servidor */

   struct sockaddr_in client;
   /* para la informaci de la direcci del cliente */

   int sin_size;
   if(argc < 2)
    {
      printf("utilice %s <Puerto> \n",argv[0]);
      exit(1);
    }
   /* A continuaci la llamada a socket() */
   if ((fd=socket(AF_INET, SOCK_STREAM, 0)) == -1 ) {
      printf("error en socket()\n");
      exit(-1);
   }
  else
     PORT=atoi(argv[1]);

   server.sin_family = AF_INET;

   server.sin_port = htons(PORT);
   /* Recuerdas a htons() de la secci "Conversiones"? =) */

   server.sin_addr.s_addr = INADDR_ANY;
   /* INADDR_ANY coloca nuestra direcci IP automicamente */

   bzero(&(server.sin_zero),8);
   /* escribimos ceros en el reto de la estructura */

   /* A continuaci la llamada a bind() */
   if(bind(fd,(struct sockaddr*)&server,
           sizeof(struct sockaddr))==-1) {
      printf("error en bind() \n");
      exit(-1);
   }
   if(listen(fd,BACKLOG) == -1) {  /* llamada a listen() */
      printf("error en listen()\n");
      exit(-1);
   }
   while(1) {
      sin_size=sizeof(struct sockaddr_in);
      /* A continuaci la llamada a accept() */
      if ((fd2 = accept(fd,(struct sockaddr *)&client, &sin_size))==-1) {
         printf("error en accept()\n");
         exit(-1);
      }
    //  printf("Se obtuvo una conexion desde %s\n",inet_ntoa(client.sin_addr) );
      /* que mostrarla IP del cliente */

      if ((numbytes=recv(fd2,buf,MAXDATASIZE,0)) != -1){
          buf[numbytes]='\0';

          if(strcmp(buf,"help") == 0){
                strcpy(buf,"Servicios:\nHora = 'time'\nFecha = 'date'\nFase Lunar = 'moon'\nCalendario Mensual = 'calender'\n");
          }

          else if(strcmp(buf,"time") == 0){
                sprintf(buf,"Hora: %02d:%02d",tm.tm_hour,tm.tm_min-4);
          }
          else if(strcmp(buf,"date") == 0){
                sprintf(buf,"Fecha: %02d-%02d-%d",tm.tm_mday,tm.tm_mon+1,tm.tm_year+1900);
          }

          else if(strcmp(buf,"moon") == 0){
                system(" curl wttr.in/moon>serv");
                fd3 = open("serv",O_RDONLY);
                numbytes = read(fd3,buf,MAXDATASIZE);
                buf[numbytes] = '\0';
          }

          else if(strcmp(buf,"calender") == 0){
                system("cal>serv");
                fd3 = open("serv",O_RDONLY);
                numbytes = read(fd3,buf,MAXDATASIZE);
                buf[numbytes] = '\0';
          }

          send(fd2,buf,MAXDATASIZE,0);
      }

      close(fd2); /* cierra fd2 */
   }
}
