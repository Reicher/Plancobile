#include "../include/client.h"

int main(int argc, char* argv[])
{
  Client* client;
  if(argc > 1)
    client = new Client(argv[1], 51717);
  else 
    client = new Client("localhost", 51717);
  
  return 0;
}
