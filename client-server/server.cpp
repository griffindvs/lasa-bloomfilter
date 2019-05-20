//Base code provided by GeeksforGeeks.org
#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#define PORT 8080 
#include "src/bloom.h"
#include "src/MurmurHash3.h"
int main(int argc, char const *argv[]) 
{ 
    int server_fd, new_socket, valread; 
    struct sockaddr_in address; 
    int opt = 1; 
    int addrlen = sizeof(address); 
    char buffer[1024] = {0}; 
    char *hello = "Hello from server"; 
       
    // Creating socket file descriptor 
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    } 
       
    // Forcefully attaching socket to the port 8080 
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, 
                                                  &opt, sizeof(opt))) 
    { 
        perror("setsockopt"); 
        exit(EXIT_FAILURE); 
    } 
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons( PORT ); 
       
    // Forcefully attaching socket to the port 8080 
    if (bind(server_fd, (struct sockaddr *)&address,  
                                 sizeof(address))<0) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 
    if (listen(server_fd, 3) < 0) 
    { 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    } 
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,  
                       (socklen_t*)&addrlen))<0) 
    { 
        perror("accept"); 
        exit(EXIT_FAILURE); 
    } 
    valread = read( new_socket , buffer, 1024); 
    printf("%s\n",buffer ); 
    send(new_socket , hello , strlen(hello) , 0 ); 
    printf("Hello message sent\n");
    
    //sockets now connected successfully, hello messages exchanged,
    //time to read data for bloom filter
    
    //****************
    //
  BloomFilter* filter = new BloomFilter(258001, .05);

  // Open fstream file
  fstream file;
  file.open("names.csv");

  //Check for opening error
  if (file.fail()) {
      cout << "Error opening file" << endl;
      exit(1);
  }

  string addStr;
  while (getline(file, addStr)) {
    char c[addStr.length()+1];
    strcpy(c, addStr.c_str());

    filter->add(c);
  }

  file.close();

  begin = "Begin testing values. Enter -1 to finish.";
  cout << begin << endl << endl;
  send(new_socket , begin , strlen(begin) , 0 );

  string check;

  while (check.compare("-1") != 0) {
    valread = read(new_socket, buffer, 1024);
    check = buffer;

    if (check.compare("-1") != 0) {
      bool res = filter->contains(buffer);
      string result;
      res ? result="Likely present" : result="Not present";
      cout << check << ": " << result << endl << endl;
      string send = check + ": " + result;
      char charSend[send.length()+1];
      strcpy(charSend, send.c_str());
      send(new_socket , charSend , strlen(charSend) , 0 );
    }
  }
    //
    //****************
    
    return 0; 
} 