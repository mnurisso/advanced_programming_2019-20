#include <iostream>

/* I can use inheritance also with templated class */
template <typename T>
struct Base {
  void foo() const { std::cout << "base foo" << std::endl; }
};

template <typename T>
struct Derived : public Base<T> {
  //void bar() const { foo(); } /* introduce a bug */
  /* If your base is templated and you get a compiler error use
   * the this pointer */
  void bar() const { this->foo(); }
};

int main() {
  Derived<int> d;
  d.bar();
}
