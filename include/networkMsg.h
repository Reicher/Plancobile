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
  
 NetMsg(MsgType t, int v) : m_type(t), m_val(v) {};
 NetMsg(const char *msg) : m_type(static_cast<MsgType>(msg[0] -'0')), m_val(msg[2]-'0') {};
  
  string ToString() { return Integer2String(m_type) + ":" + Integer2String(m_val); };
  
  MsgType GetMsgType() const {return m_type;};
  int GetValue() const {return m_val;};

 private:
  MsgType m_type;
  int m_val;
};
