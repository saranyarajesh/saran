#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
int main(int argc,char *argv[])
{
  int sockfd,portno;
  struct sockaddr_in serv_addr;
  struct hostent *server;
  char buffer[256];
  portno = atoi(argv[2]);
  sockfd = socket(AF_INET,SOCK_STREAM,0);
  server=gethostbyname(argv[1]);
  //bzero((char *) &serv_addr,sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr,(char *)&serv_addr.sin_addr.s_addr,server->h_length);
  serv_addr.sin_port = htons(portno);
  connect(sockfd,&serv_addr,sizeof(serv_addr));
  printf("enter the msg:");
  bzero(buffer,256);
  fgets(buffer,255,stdin);
  write(sockfd,buffer,strlen(buffer));
  bzero(buffer,256);
  printf("enter the ip:");
  fgets(buffer,255,stdin);
  write(sockfd,buffer,strlen(buffer));
  read(sockfd,buffer,255);
  printf("%s",buffer);
  return 0;
}
