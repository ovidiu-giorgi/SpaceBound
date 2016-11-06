#include <Debug.h>

Debug::Debug()
{

}

Debug::~Debug()
{

}

Debug* Debug::Instance()
{
  static Debug instance;

  return &instance;
}

void Debug::Log(std::string message)
{
  std::ofstream fout;
  fout.open("error.log", std::ofstream::out | std::ofstream::app);
  fout << message << '\n';
  fout.close();
}

void Debug::Log(std::string fileName, std::string message)
{
  std::ofstream fout;
  fout.open(fileName, std::ofstream::out | std::ofstream::app);
  fout << message << '\n';
  fout.close();
}