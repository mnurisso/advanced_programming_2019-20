#include <iostream>

struct X {
  char member;
};

int main() {
  X x1;                 // default ctor
  X x2{x1};             // copy ctor
  X x3{std::move(x2)};  // move ctor
  X x4{};               // default ctor calling {} to each member
  x4 = x3;              // copy assignment. The object has to be already constructed
  X x5;                 // default ctor
  x5 = std::move(x4);   // move assignment. Same as copu assignement
  std::cout << x5.member << std::endl;  // what do you expect??
  return 0;
}
