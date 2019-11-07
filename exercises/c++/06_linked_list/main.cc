#include "list.h"

int main(){
	try{
		List<int> l{};
		
		l.insert(4, method::push_back);
		l.insert(5, method::push_back);
		l.insert(3, method::push_front);
		
		std::cout << "Constructor check: " << std::endl;
		std::cout << l << std::endl;
		
		auto ol = l;
		
		std::cout << "Copy sematic check: " << std::endl;
		std::cout << ol << std::endl;
		
		l.insert(14, method::push_front);
		
		std::cout << "Deep copy check (should be different): " << std::endl;
		std::cout << l << std::endl;
		std::cout << ol << std::endl;
		
	}//catch(std::expception& e){
		//std::cerr << e.what() << std::endl;
	//}
	catch(...){
		std::cerr << "Unknown exception" << std::endl;
	}
	return 0;
}