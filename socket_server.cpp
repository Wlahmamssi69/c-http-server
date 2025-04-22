#include <stdio.h>

#include <Winsock2.h>

int main()
{
   int sc = socket(AF_INET,SOCK_STREAM,0);
   printf("%d",sc);
}
