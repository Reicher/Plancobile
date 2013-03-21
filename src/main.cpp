#include <iostream>
#include <string>

#include "../include/server.h"
#include "../include/DCMotor.h"

using namespace std;

const string version = "indev";

int main(int argc, char* argv[])
{
  cout << "Plancobile " << version << endl << endl;

  Server piServer(51717);  

  DCMotor mainMotor(0);

  mainMotor.Set(0.7);

  return 0;
}
