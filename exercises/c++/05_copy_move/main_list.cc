#include "list.h"

int main(){
	/* Ctor check */
	std::cout << "List constructor test: \n";
	List<double> l{0.4,52.3,3.2};
	
	/* Check size function */
	std::cout << "The size is: " << l.size() << std::endl;
	l.print();
	//std::cout << l << std::endl;
	
	return 0;
}