#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#include <fstream>
#include <iostream>

void terminate_with_error(int sock) {
  close(sock);
  perror("Error Binding Socket:");
  exit(1);
}

int main(int argc, char ** argv) {

  if (argc != 2){
    printf ("Usage: client_stream <server_address>\n");
    exit(1);
  }

  int sock;
  struct sockaddr_in serverAddr; // internet address socket
  socklen_t sin_size = sizeof(struct sockaddr_in);

  // Create IPv4 Socket in TCP, 0 is the only protocol
  sock = socket(AF_INET, SOCK_STREAM, 0);

  if (sock == -1) { // If socket can't be made
    perror("Error Creating Socket");
    exit(1);
  }

  // initializing
  memset((char *) &serverAddr, 0, sizeof(serverAddr));
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(9999);
  struct hostent *server = gethostbyname(argv[1]); // one hostent per thread, it's IPv4

  if (server == NULL) // If server can't be initialized
    terminate_with_error(sock);

  memcpy((char*) &serverAddr.sin_addr.s_addr, (char*) server->h_addr, server->h_length);
  memset(&(serverAddr.sin_zero), 0, 8);

  // Connect sockets
  connect(sock, (sockaddr*) &serverAddr, sizeof(serverAddr));

  std::string input = "";

  // start loop here!
  while (true){

    if (sock == -1)
      terminate_with_error(sock);

    getline(std::cin, input);
    if (input == "exit") {
      break;
    } else if (input == "clear" || input == "CLS") {
      std::cout << std::string(70, '\n');
    } else {
      const char* input2 = input.c_str();
      send(sock, input2, strlen(input2), 0);
    }
  }
    // end loop here!

  close (sock);

}
