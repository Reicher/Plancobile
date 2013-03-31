#include "../include/client.h"

int main(int argc, char* argv[])
{
<<<<<<< HEAD
	Client* client;
	if(argc > 1)
		client = new Client(argv[1], 51717);
	else
		client = new Client("localhost", 51717);
	
=======
  Client* client;
  if(argc > 1)
    client = new Client(argv[1], 51717);
  else 
    client = new Client("localhost", 51717);
  
>>>>>>> 5548345afde83970f2fbb9952aac4556e2318e45
  return 0;
}
