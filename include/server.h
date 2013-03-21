#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <list>
#include <thread>

#include "networkMsg.h"


using namespace std;

class Server
{
 public:
  Server(int portnum = 51717);
  ~Server();

  bool UnreadMsg();
  NetMsg GetMsg();

 private:
  void OpenSocket();
  void BindSocket();
  void ListenAfterStuff();

  void Error(const char *msg);

  int m_sockfd, m_newsockfd, m_portNum;
  socklen_t m_clilen;
  char buffer[256];

  struct sockaddr_in m_serv_addr, m_cli_addr;

  list<NetMsg> m_unReadMsgs;
};
