#pragma once

#include <string>
#include <sstream>

using namespace std;

inline string Integer2String(int num)
{
  return static_cast<ostringstream*>( &(ostringstream() << num) ) -> str();
};
