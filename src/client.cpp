#include "../include/client.h"

Client::Client(const char *host, int portNum)
{
  OpenSocket();
  ConnectToHost(host, portNum);
  
  SendMsg(NetMsg(Ok, 23));
  GetResponse();

  Disconnect();
}

void Client::OpenSocket()
{
  m_sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(m_sockfd < 0)
    error("ERROR opening socket!");

}
void Client::SetHost(const char* host)
{
  m_pServer = gethostbyname(host);
  if(m_pServer == NULL)
    {
      error("ERROR no such host!");
    }
}
void Client::ConnectToHost(const char* host, int portNum)
{
  SetHost(host);

  bzero((char *) &m_serv_addr, sizeof(m_serv_addr));
  m_serv_addr.sin_family = AF_INET;
  bcopy((char *)m_pServer->h_addr, (char *)&m_serv_addr.sin_addr.s_addr, m_pServer->h_length);
  m_serv_addr.sin_port = htons(portNum);
  if(connect(m_sockfd, (struct sockaddr *) &m_serv_addr, sizeof(m_serv_addr)) < 0)
    error("ERROR connecting!");
}

void Client::Disconnect()
{
  close(m_sockfd);
}

bool Client::SendMsg(NetMsg msg)
{
  bzero(m_buffer, 256);
  sprintf(m_buffer, "%s", msg.ToString().c_str());
  m_n = write(m_sockfd, m_buffer, strlen(m_buffer));
  if(m_n < 0)
    error("ERROR writing to socket!");
}

NetMsg Client::GetResponse()
{
  bzero(m_buffer, 256);
  m_n = read(m_sockfd, m_buffer, 255);
  if(m_n < 0)
    error("ERRPR readomg from socket!");

  cout << m_buffer; //FOr now!

  return NetMsg(Error, 0);
}

void Client::error(const char *msg)
{
  perror(msg);
  exit(1);
}
