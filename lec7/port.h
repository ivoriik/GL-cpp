#ifndef PORT_H
#define PORT_H

#include <iostream>

static const int portStLen = 20;

class Port {
private:
  char *brand;
  char style[portStLen]; // e.g. tawny, ruby, vintage
  int bottles;

public:
  Port(const char *br = "none", const char *st = "none", int b = 0);
  Port(const Port &p);
  virtual ~Port() {
    std::cout << "\nPort::Destructor\n";
    delete[] brand;
  }

  Port &operator=(const Port &p);
  Port &operator+=(int b); // adds b to bottles
  Port &operator-=(int b); // subtracts b from bottles, if possible

  int BottleCount() const { return bottles; }
  const char *GetBrand() const { return brand; }
  const char *GetStyle() const { return &style[0]; }
  void swap(Port &p);
  virtual void Show() const;
  friend std::ostream &operator<<(std::ostream &os, const Port &p);
};

#endif