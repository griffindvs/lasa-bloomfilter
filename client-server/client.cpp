//Base code provided by GeeksforGeeks.org
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#define PORT 8080

int main(int argc, char const *argv[])
{
    struct sockaddr_in address;
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *hello = "Hello from client";
    char buffer[1024] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }
    send(sock , hello , strlen(hello) , 0 );
    printf("Hello message sent\n");
    valread = read( sock , buffer, 1024);
    printf("%s\n",buffer );

    //sockets now connected successfully, hello messages exchanged,
    //time to prompt data for bloom filter

    valread = read( sock , buffer, 1024);
    cout << buffer << endl << endl; // message from server to enter names

    string name;
    while(name.compare("-1") != 0)
    {
      cout << "Enter username: ";
      cin >> name;
      char charName[name.length()+1]; // convert name to char array
      strcpy(charName, name.c_str());
      cout << "Checking database for " << name << "..." << endl;
      send(sock, name,strlen(name), 0);
      valread = read(sock, buffer, 1024);
      cout << buffer << endl;
    }

    return 0;
}
