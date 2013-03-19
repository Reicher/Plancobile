#include "../include/server.h"

Server::Server(int portnum)
  : m_portNum(portnum)
{
  int n;

  m_sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(m_sockfd < 0)
    {
      cout << "Error opening socket!" << endl;
      exit(1);
    }

  bzero((char *) &m_serv_addr, sizeof(m_serv_addr));
  
  m_serv_addr.sin_family = AF_INET;
  m_serv_addr.sin_addr.s_addr = INADDR_ANY;
  m_serv_addr.sin_port = htons(m_portNum);

  if(bind(m_sockfd, (struct sockaddr *) &m_serv_addr, sizeof(m_serv_addr)) > 0)
    Error("Error on binding!");

  listen(m_sockfd, 5);
  m_clilen = sizeof(m_cli_addr);
  m_newsockfd = accept(m_sockfd, (struct sockaddr *) &m_cli_addr, &m_clilen);
  if(m_newsockfd < 0)
    Error("Error on accept!");

  bzero(buffer, 256);
  n = read(m_newsockfd, buffer, 255);
  if(n < 0)
    Error("Error reading from sock!");

  cout << "Message from client: " << buffer << endl;

  n = write(m_newsockfd, "I got your message", 18);
  if(n < 0)
    Error("ERROR writing to socket");

  close(m_newsockfd);
  close(m_sockfd);
}

void Server::Error(const char *msg)
{
  perror(msg);
  exit(1);
}
