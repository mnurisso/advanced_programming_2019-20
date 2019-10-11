#include <iostream>
#include <new>

//template <typename T>
//void ArrayCreation(T*, std::size_t);

template <typename T>
T* ArrayCreation();

template <typename R>
void ArrayReverse(R*, std::size_t);

int main(){	
	/* Create the array */
	double *arr;
	*arr = ArrayCreation();
	
	/* Reverse the order */
	//ArrayReverse(arr,n);
	
	delete[] arr;
	return 0;
}

template <typename T>
T* ArrayCreation(){
	std::size_t n;
	
	/* Asking for array length */
	std::cout << "Insert array size:" << std::endl;
	std::cin >> n;
	T* arr{new T[n]};
	
	std::cout << "The initial array is:" << std::endl;
	std::cout << "[ ";
	
	for(std::size_t i{0}; i<n; ++i){
		arr[i] = i;
		std::cout << arr[i] << " ";
	}
	
	std::cout << "]" << std::endl;
	return arr;
}

//template <typename T>
//void ArrayCreation(T* arr, std::size_t n){
//	T* arrt{new T[n]};
//	
//	std::cout << "The initial array is:" << std::endl;
//	std::cout << "[ ";
//	
//	for(std::size_t i{0}; i<n; ++i){
//		arrt[i] = i;
//		arr[i] = arrt[i];
//		std::cout << arrt[i] << " ";
//	}
//	
//	std::cout << "]" << std::endl;
//	delete[] arrt;
//}

template <typename R>
void ArrayReverse(R* arr, std::size_t n){
	
	std::cout << "The reversed array is:" << std::endl;
	std::cout << "[ ";
	
	for(std::size_t i{n}; i>0; i--){
		std::cout << arr[i-1] << " ";
	}
	
	std::cout << "]" << std::endl;
}