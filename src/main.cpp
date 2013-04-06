#include <iostream>
#include <string>

#include "../include/server.h"
#include "../include/DCMotor.h"
#include "../include/networkMsg.h"

using namespace std;

const string version = "indev";

int main(int argc, char* argv[])
{
  cout << "Plancobile " << version << endl << endl;

  Server piServer(51717);  
  DCMotor mainMotor(0);


  while(1)
    {
      if( !piServer.HaveClient() )
	piServer.WaitForClient();
      
      if( piServer.HaveMessage() ){
	
	NetMsg cmd = piServer.Read();
	switch(cmd.GetMsgType())
	  {
	  case Drive:
	    cout << "DRIVE: " << cmd.GetValue() << endl;
	    break;
	  case Bearing:
	    cout << "BEARING!" << cmd.GetValue() << endl;
	    break;
	  case Error:
	    continue;
	    break;
	  default:
	    cout << "Something awful happend:(" << endl;
	  }
      }
    }

  return 0;
}
