#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

using namespace std;

class Client
{
 public:
  Client(const char* host, int portNum);

 private:
  void error(const char *msg);

  int m_sockfd, m_portNum, m_n;
  struct sockaddr_in m_serv_addr;
  struct hostent *m_pServer;
  char m_buffer[256];
};
