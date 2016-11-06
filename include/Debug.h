#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>
#include <fstream>

class Debug
{
public:
  static Debug* Instance();
  
  void Log(std::string message);
  void Log(std::string fileName, std::string message);

private:
  Debug();
  ~Debug();
  Debug(const Debug& other);
  Debug& operator=(const Debug& other);
};

#endif