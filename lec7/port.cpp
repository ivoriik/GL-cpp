#include "port.h"
#include <algorithm>
#include <cstring>

Port::Port(const char *br, const char *st, int b)
    : brand(new char[strlen(br) + 1]), bottles(b) {
  std::cout << "Port(const char* br, const char* st, int b)" << std::endl;
  strcpy(brand, br);
  strncpy(style, st, portStLen);
}

Port::Port(const Port &p)
    : brand(new char[strlen(p.brand) + 1]), bottles(p.bottles) {
  std::cout << __func__ << ": copy" << std::endl;
  strcpy(brand, p.brand);
  strncpy(style, p.style, portStLen);
}

Port &Port::operator=(const Port &p) {
  std::cout << __func__ << ": assignment" << std::endl;
  if (this != &p) {
    Port(p).swap(*this);
  }
  return *this;
}

Port &Port::operator+=(int b) {
  this->bottles += b;
  return *this;
}

Port &Port::operator-=(int b) {
  if (this->bottles >= b) {
    this->bottles -= b;
  } else {
    std::cout << "oops! stocks are depleted the ship is sinking" << std::endl;
  }
  return *this;
}

void Port::Show() const {
  std::cout << "Brand: " << this->brand << std::endl;
  std::cout << "Kind: " << this->style << std::endl;
  std::cout << "Bottles: " << this->bottles << std::endl;
}

void Port::swap(Port &p) {
  std::cout << "Port: " << __func__ << std::endl;
  std::swap(brand, p.brand);
  std::swap(style, p.style);
  std::swap(bottles, p.bottles);
}

std::ostream &operator<<(std::ostream &os, const Port &p) {
  return os << p.GetBrand() << ", " << p.GetStyle() << ", " << p.BottleCount();
}