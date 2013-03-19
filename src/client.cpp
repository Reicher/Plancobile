#include "../include/client.h"

Client::Client(const char *host, int portNum)
  : m_portNum( portNum )
{
  m_sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(m_sockfd < 0)
    error("ERROR opening socket!");
  
  m_pServer = gethostbyname(host);
  if(m_pServer == NULL)
    {
      error("ERROR no such host!");
    }

  bzero((char *) &m_serv_addr, sizeof(m_serv_addr));
  m_serv_addr.sin_family = AF_INET;
  bcopy((char *)m_pServer->h_addr, (char *)&m_serv_addr.sin_addr.s_addr, m_pServer->h_length);
  m_serv_addr.sin_port = htons(m_portNum);
  if(connect(m_sockfd, (struct sockaddr *) &m_serv_addr, sizeof(m_serv_addr)) < 0)
    error("ERROR connecting!");

  cout << "Enter message: ";
  bzero(m_buffer, 256);
  fgets(m_buffer, 255, stdin);
  m_n = write(m_sockfd, m_buffer, strlen(m_buffer));
  if(m_n < 0)
    error("ERROR writing to socket!");

  bzero(m_buffer, 256);
  m_n = read(m_sockfd, m_buffer, 255);
  if(m_n < 0)
    error("ERRPR readomg from socket!");

  cout << m_buffer;
  close(m_sockfd);
}

void Client::error(const char *msg)
{
  perror(msg);
  exit(1);
}
