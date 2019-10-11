#include <iostream>
#include <new>

double* ArrayCreation(std::size_t);
void ArrayReverse(double*, std::size_t);

int main(){	
	std::size_t n;
	
	/* Asking for array length */
	std::cout << "Insert array size:" << std::endl;
	std::cin >> n;
	
	/* Create the array */
	double *arr;
	arr = ArrayCreation(n);
	
	std::cout << "The initial array is:" << std::endl;
	std::cout << "[ ";
	
	for(std::size_t i{0}; i<n; ++i){
		std::cout << arr[i] << " ";
	}
	
	std::cout << "]" << std::endl;
	
	/* Reverse the order */
	ArrayReverse(arr,n);
	
	delete[] arr;
	return 0;
}


double* ArrayCreation(std::size_t n){
	double* arr{new double[n]};
	
	std::cout << "The initial array is:" << std::endl;
	std::cout << "[ ";
	
	for(std::size_t i{0}; i<n; ++i){
		arr[i] = i;
		std::cout << arr[i] << " ";
	}
	
	std::cout << "]" << std::endl;
	return arr;
}

void ArrayReverse(double* arr, std::size_t n){
	
	std::cout << "The reversed array is:" << std::endl;
	std::cout << "[ ";
	
	for(std::size_t i{n}; i>0; i--){
		std::cout << arr[i-1] << " ";
	}
	
	std::cout << "]" << std::endl;
}