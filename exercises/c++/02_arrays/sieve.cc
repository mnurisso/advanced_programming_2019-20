#include <iostream>
#include <cmath>
#include <new>

/***********************************************/
/*                PROTOTYPES                   */
/***********************************************/
bool* ArrayCreation(std::size_t);

/***********************************************/
/*                 MAIN                        */
/* Implement sieve of Eratosthenes method      */
/* to find prime numbers                       */
/***********************************************/
int main(){
	std::size_t  n; 			// vector size
	bool *arr;						// array
	
	std::cout << "You want to evaluate the prime ";
	std::cout << "numbers up to which value?" << std::endl;
	std::cin  >> n;
	std::cout << std::endl;
	
	/* Allocate array */
	arr = ArrayCreation(n);
	for(unsigned int i = 0; i<n; i++){
		arr[i] = true;
	}
	
	/* Sieve algorithm */
	for(unsigned int i = 2; i<std::sqrt(n); i++){
		//std::cout << i << std::endl;
		if(arr[i] == true){
			for(unsigned int j=i*i; j<n; j+=i){
				arr[j] = false;
			}
		}
	}
	
	/* Print true values */
	for(unsigned int i = 2; i<n; i++){
		if(arr[i] == true){
			std::cout << i << " is a prime number" << std::endl;
		}
	}
	
	/* Deallocate array */
	delete[] arr;
	
	return 0;
}

/***********************************************/
/*                FUNCTIONS                    */
/***********************************************/

/* Create a boolean array of size n*/
bool* ArrayCreation(std::size_t n){
        bool* arr{new bool[n]};
        return arr;
}