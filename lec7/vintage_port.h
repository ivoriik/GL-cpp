#ifndef VINTAGE_PORT_H
#define VINTAGE_PORT_H

#include "port.h"

static const char *vStyle = "vintage";

class VintagePort : public Port { // style always == "vintage"
private:
  char *nickname; // like "The Noble", "Old Velvet", etc.
  int year;       // year of bottling
public:
  VintagePort();
  VintagePort(const char *br, int b, const char *nn, int y);
  VintagePort(const VintagePort &vp);
  ~VintagePort() override {
    std::cout << "\nVintagePort::Destructor\n";
    delete[] nickname;
  }

  VintagePort &operator=(const VintagePort &vp);
  void swap(VintagePort &vp);
  void Show() const override;
  const char *GetNickname() const { return this->nickname; };
  int GetYear() const { return this->year; };
  friend std::ostream &operator<<(std::ostream &os, const VintagePort &vp);
};

#endif