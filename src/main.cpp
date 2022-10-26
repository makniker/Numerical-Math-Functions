#include <map>
#include <functional>
#include <iostream>

#include "Commands.hpp"

int main()
{
  using lab = std::function< void(std::ostream&, std::istream&)>;
  std::map< std::string, lab> labsDict
  {
	  {"lab2", nmath::lab2}
  };
  try
  {
	  std::string commandName;
	  while (std::cin >> commandName)
	  {
		  labsDict.at(commandName)(std::cout, std::cin);
	  }
  }
  catch (...)
  {
	  std::cerr << "wrong name";
  }
  return 0;
}
