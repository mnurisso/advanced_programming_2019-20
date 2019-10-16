#include <iostream>
#include <new>

/* Prototypes */
int* ArrayCreation(std::size_t);
void ArrayPrint (int *, int);

int main(){
	std::size_t n = 100;
	unsigned int remainder;			// remainder of integer division
	unsigned int pcount = 0;		// prime numbers counter
	int *arr;
	bool pstat = true;					// prime status
	
	/* Allocate the array */
	arr = ArrayCreation(n);
	
	arr[0] = 2; // 2 is the first prime number
	
	for(unsigned int i=3; i<=n; i++){/* analysis i number */
		/* prime analysis*/
		unsigned int j = 0;
		
		while(pstat == true && j<=pcount){/* loop over previous prime numbers */
			remainder = i%arr[j];
			
			if(remainder == 0){/* not a prime number */
				pstat = false;
			}
			
			j++;
		}
		if(pstat == true){/* prime number found */
			pcount++;
			arr[pcount] = i;
		}else pstat = true;/* restet bool variable */
	}
	
	/* Print array */
	ArrayPrint(arr,pcount+1);
	
	/* Deallocate the array */
	delete[] arr;
	
	return 0;
}

/* Create a integer array of size n*/
int* ArrayCreation(std::size_t n){
	int* arr{new int[n]};
	return arr;
}

/* Print an integer array*/
void ArrayPrint (int *a, int n)
{
	using namespace std;
	cout << "{" ;
	for (int i = 0; i<n; i++)
	{
		cout << a[i];
		if (i<n-1)
			cout << ", ";
	}
	cout << "}" << endl;
}
