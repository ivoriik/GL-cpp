#include "port.h"
#include "vintage_port.h"
#include <iostream>

/*
 * 2) Some class members are overriden because they need different behavior for
 * derived class. Also operator = and copy constrructor are always hidden by the
 * derived class implementation unless explicit using declaration is provided,
 * so should be overriden too.
 *
 * 3) Virtual functions don't know about parameter's inheritance: A function's
 * signature needs to be the same for virtual to come into play. So if
 * operator=() (or <<()) is made virtual, the call will never act as a virtual
 * function derrived class, because the parameters (and in case of =() return
 * value) of those operators are different. The function Port::operator=(const
 * Port& oth) and VintagePort::operator=(const VintagePort& oth) are completely
 * different and seen as 2 distinct functions. The same are for operator <<():
 * std::ostream& operator<<(std::ostream& os, const Port& p)
 * std::ostream& operator<<(std::ostream& os, const VintagePort& vp)
 */

/*
 * A primitive main is provided for demonstrative purposes.
 */

int main() {
  Port p1("VillaKrym", "Budget", 20);
  VintagePort vp1("Koblevo", 2, "RedSnapper", 1991);

  std::cout << std::endl;

  p1.Show();
  std::cout << "Port: " << p1 << std::endl;

  std::cout << std::endl;

  vp1.Show();
  std::cout << "VintagePort: " << vp1 << std::endl;

  std::cout << std::endl;

  Port p2 = vp1;
  p2.Show();

  p2 += 10;
  p2.Show();

  std::cout << std::endl;

  VintagePort vp2;
  std::cout << "VintagePort 2 Default constructor: " << vp2 << std::endl;
  p2 = vp2;
  std::cout << "Port after assignment: " << p2 << std::endl;
  vp2 = vp1;
  std::cout << "here" << std::endl;
  std::cout << "VintagePort 2: " << vp2 << std::endl;
  vp2 += 100;
  vp1 -= 20;
  vp2 -= 20;
  std::cout << "VintagePort 1: " << vp1 << std::endl;
  std::cout << "VintagePort 2: " << vp2 << std::endl;

  return 0;
}