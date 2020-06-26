#include "vintage_port.h"
#include <algorithm>
#include <cstring>
#include <iostream>

VintagePort::VintagePort()
    : Port("none", vStyle, 0), nickname(new char[5]), year(0) {
  std::cout << "VintagePort()" << std::endl;
  strcpy(nickname, "none");
}

VintagePort::VintagePort(const char *br, int b, const char *nn, int y)
    : Port(br, vStyle, b), nickname(new char[strlen(nn) + 1]), year(y) {
  std::cout << "VintagePort(const char* br, int b, const char* nn, int y)"
            << std::endl;
  strcpy(nickname, nn);
}

VintagePort::VintagePort(const VintagePort &vp)
    : Port(vp), nickname(new char[strlen(vp.nickname) + 1]), year(vp.year) {
  std::cout << __func__ << ": copy" << std::endl;
  strcpy(nickname, vp.nickname);
}

VintagePort &VintagePort::operator=(const VintagePort &vp) {
  std::cout << __func__ << ": assingment" << std::endl;
  if (this != &vp) {
    Port::operator=(vp);
    VintagePort(vp).swap(*this);
  }
  return *this;
}

void VintagePort::swap(VintagePort &p) {
  std::cout << "VintagePort: " << __func__ << std::endl;
  std::swap(nickname, p.nickname);
  std::swap(year, p.year);
}

void VintagePort::Show() const {
  Port::Show();
  std::cout << "Nickname: " << this->nickname << std::endl;
  std::cout << "Year: " << this->year << std::endl;
}

std::ostream &operator<<(std::ostream &os, const VintagePort &vp) {
  return os << static_cast<Port>(vp) << ", " << vp.GetNickname() << ", "
            << vp.GetYear();
}
