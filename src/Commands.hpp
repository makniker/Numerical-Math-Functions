#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include <iosfwd>
#include <map>
#include <functional>
#include <string>

namespace nmath
{
  using lab = std::function<void(std::ostream &, std::istream &)>;
  using LabDict = std::map<std::string, nmath::lab>;
  std::ostream &printLabsList(std::ostream &, const LabDict &);
  void lab2(std::ostream &, std::istream &);
}

#endif
