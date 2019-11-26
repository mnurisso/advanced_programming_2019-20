#include <iostream>

struct Base {
  Base() { std::cout << "Base\n"; }
  ~Base() { std::cout << "~Base\n"; }
  //virtual ~Base() { std::cout << "~Base\n"; } /*fix the memory leak */
};

struct Derived : public Base {
  Derived() { std::cout << "Derived\n"; }
  ~Derived() { std::cout << "~Derived\n"; }
};

int main() {
  { Derived d; }

  std::cout << "\n\npointers\n";
  Base* p = new Derived;
  delete p; /* doesn't delete the derived class */

  return 0;
}
