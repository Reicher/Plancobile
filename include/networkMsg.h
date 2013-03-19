#pragma once

#include "helpers.h"
#include <string>

using namespace std;

enum MsgType
{
  Ok,
  Error,
  Drive,
  Bearing
};

class NetMsg
{
 public:
 NetMsg(MsgType t, int v) : m_type(t), m_val(v) {}
  string ToString() { return Integer2String(m_type) + ":" + Integer2String(m_val); }
  
 private:
  MsgType m_type;
  int m_val;
};
