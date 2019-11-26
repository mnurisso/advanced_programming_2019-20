#include <iostream>

/* Adding the virtual keyword implies the creation of a pointer 
 * so that 8 bit are required for the foo class (and the same
 * for the derived one  
 * ************************************************************ */
struct foo{
	virtual void bar(){std::cout<<"in foo	n";}
};

struct derived: public foo{
};

int main(){
	std::cout << sizeof(foo) << std::endl;
	std::cout << sizeof(derived) << std::endl;
	return 0;
}
