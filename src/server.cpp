#include "../include/server.h"

Server::Server(int portnum)
  : m_portNum(portnum)
{
  OpenSocket();
  BindSocket();
  WaitForClient();
}

Server::~Server()
{
  close(m_newsockfd);
  close(m_sockfd);
}

NetMsg Server::Read()
{
  int n;

  bzero(buffer, 256);
  n = read(m_newsockfd, buffer, 255);
  if(n < 0)
    Error("Error reading from sock!");
  
  if(buffer[0] == 0)
    return NetMsg(MsgType::Error, 0);

  cout << "Message from client: " << buffer << endl;

  return NetMsg(buffer);
}

void Server::OpenSocket()
{
  m_sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(m_sockfd < 0)
    {
      cout << "Error opening socket!" << endl;
      exit(1);
    }
}

void Server::BindSocket()
{
  bzero((char *) &m_serv_addr, sizeof(m_serv_addr));
  
  m_serv_addr.sin_family = AF_INET;
  m_serv_addr.sin_addr.s_addr = INADDR_ANY;
  m_serv_addr.sin_port = htons(m_portNum);

  if( bind(m_sockfd, (struct sockaddr *) &m_serv_addr, sizeof(m_serv_addr)) < 0 )
    Error("Error on binding!");
}

void Server::Error(const char *msg)
{
  perror(msg);
  exit(1);
}

bool Server::WaitForClient()
{
  cout << "Waiting for client to connect......";

  listen(m_sockfd, 5);

  m_clilen = sizeof(m_cli_addr);
  m_newsockfd = accept(m_sockfd, (struct sockaddr *) &m_cli_addr, &m_clilen);
  
  if(m_newsockfd < 0){
    Error("Error on accept!");
    return false;
  }
  
   cout << "Connected!" << endl;
   return true;
}

bool Server::HaveClient()
{
  fd_set rfd;
  FD_ZERO(&rfd);
  FD_SET(m_sockfd, &rfd);
  timeval tv = {0};
  select(m_sockfd+1, &rfd, 0, 0, &tv);
  if(FD_ISSET(m_sockfd, &rfd))
    return false;

  return true;
}

bool Server::HaveMessage()
{
  int n = 0;
  ioctl(m_sockfd, FIONREAD, &n);
  return n == 0;
}
