#include <iostream>
#include <string>
#include <pthread.h>

#include "../include/server.h"
#include "../include/DCMotor.h"

using namespace std;

const string version = "indev";

int main(int argc, char* argv[])
{
  cout << "Plancobile " << version << endl << endl;

  Server piServer(51717);  
  pthread_t serverThread;

  pthread_create(&serverThread, NULL, &Server::runHelper, &piServer);
  pthread_join(serverThread, NULL);

  DCMotor mainMotor(0);

  mainMotor.Set(0.7);

  return 0;
}
