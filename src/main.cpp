#include <iostream>

#include "Commands.hpp"

int main()
{
  nmath::LabDict labsDict
  {
    {"2", nmath::lab2}
  };
  while (std::cin.good())
  {
    try
    {
      nmath::printLabsList(std::cout, labsDict);
      std::cout << "Enter lab number:\n";
      std::string commandName;
      std::cin >> commandName;
      labsDict.at(commandName)(std::cout, std::cin);
    }
    catch (...)
    {
      std::cout << "wrong name\n";
    }
  }
  return 0;
}
