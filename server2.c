#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
int main(int argc,char *argv[])
{
  int sockfd,newsockfd,portno,clilen;
  char buffer[256];
  String s;
  struct sockaddr_in serv_addr,cli_addr;
  sockfd=socket(AF_INET,SOCK_STREAM,0);
  bzero((char *) &serv_addr,sizeof(serv_addr));
  portno = atoi(argv[1]);
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno);
  bind(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr));
  listen(sockfd,5);
  clilen = sizeof(cli_addr); 
  newsockfd = accept(sockfd,(struct sockaddr *) &cli_addr,&clilen);
  bzero(buffer,256);
  read(newsockfd,buffer,255);
  printf("msg from the client : %s",buffer);
  bzero(buffer,256);
  s=read(newsockfd,buffer,255);
  printf("ip from the client : %s",buffer);
  
  arp -a s | awk '{buffer=$4}';
  write(newsockfd,buffer,255);
  bzero(buffer,256);
  write(newsockfd,"here comes ",11);
  return 0;
}
