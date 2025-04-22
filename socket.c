#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
  int socketFD = socket(AF_INET,SOCK_STREAM,0);
  //  printf("%d",socketFD);

  char * ip = "142.250.31.138";
  // pointer to the address
   struct  sockaddr_in addr;
  addr.sin_family = AF_INET;
  
  //big-endian Most significant byte first
  addr.sin_port = htons(80);
  
  // presentation
  inet_pton(AF_INET,ip,&addr.sin_addr.s_addr);

  // connect to google server
  // casting struct socket_in to socket.
  // why casting ? ==> Because connect() is a generic function — it doesn’t just support IPv4 (sockaddr_in), but also:
  // IPv6 (struct sockaddr_in6)
  // UNIX domain sockets (struct sockaddr_un)
  int result = connect(socketFD,(const struct sockaddr *) &addr,sizeof addr);
  
  // testing connection :  success => 0 ; error =>-1
  if(result == 0)
  printf("Connection successful\n");
  char * request;
  request = "GET / HTTP/1.1\r\nHost:google.com\r\n\r\n";
  send(socketFD,request,strlen(request),0);


  char buffer[1024];
  recv(socketFD,buffer,1024,0);
 
  printf("response : %s\n",buffer);



  
  
  
}
