#include <array>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <utility>

template <class T>
void PrintMatrix (T& matr, std::size_t row, std::size_t col){
	for(std::size_t i=0; i<row; i++){
		for(std::size_t j=0; j<col; j++){
			std::cout << std::setw(2) << matr[i * col + j] << " ";
		}
	std::cout << std::endl;
	}
}

template <class T>
void TransposeMatrix (T& matr, std::size_t row, std::size_t col){
	std::array<double,100> arr_c{0};
	
	/* copy the original array */
	for(std::size_t i=0; i<row; i++){
		for(std::size_t j=0; j<col; j++){
			arr_c[i * col + j] = matr[i * col + j];
		}
	}
	
	/* transpose the matrix */
	for(std::size_t i=0; i<col; i++){
		for(std::size_t j=0; j<row; j++){
			matr[i * row + j] = arr_c[j * col + i];
		}
	}
}
int main(int argc, char* argv[]){
	std::size_t row, col;
	
	/* rows and columns from terminal */
	std::istringstream is1{argv[1]};
	is1 >> row;

	std::istringstream is2{argv[2]};
	is2 >> col;

	if(col*row > 100){
		std::cout << "Dimension not supported" << std::endl;
		return 1;
	}
	
	/* Initialize the matrix */
	std::array<double,100> arr{0};
	unsigned int i = 0;
	for (auto& x : arr){
		x += i;
		i++;
	}
	
	/* Print initial matrix */
	std::cout << "The original matrix is:" << std::endl;
	PrintMatrix(arr,row,col);
	
	/* Transpose matrix */
	TransposeMatrix(arr,row,col);
	std::cout << "The transpose matrix is:" << std::endl;
	PrintMatrix(arr,col,row);
	
	return 0;
}