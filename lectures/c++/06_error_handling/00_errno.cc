#include <cmath>
#include <iostream>

int main() {
  double d = std::sqrt(4);
  std::cout << d << " " << errno << std::endl;

  d = std::sqrt(-4);
  std::cout << d << " " << errno << std::endl;
  
  d = std::sqrt(4); /* errno value is still modified */
  std::cout << d << " " << errno << std::endl;
  
  errno = 0; /* user can reset the error if the result is fine */
  std::cout << d << " " << errno << std::endl;
  
  return 0;
}
