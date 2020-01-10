#include <iostream>
#include "hello.h"

int main(){
	std::cout << "Testing libhello.so with a custom Makefile" << std::endl;

	hello_world();
	hello_dummy();
	hello_foo();

	std::cout << "Test done!" << std::endl;

	return 0;
}
