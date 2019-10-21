#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <utility>
#include <vector>
/*********************************************************/

template <typename T>
T MeanVector(const std::vector<T>& v);

template <typename T>
T MedianVector(std::vector<T>& v);

template <typename T>
void PrintVector(const std::vector<T>& v, const std::string& s);

/*********************************************************/
int main(){
	std::vector<double> v;
	double mean   = 0.0;
	double median = 0.0;
	
	/* Open file */
	std::ifstream input("temperatures.txt"); /* Open the file */
	std::string line;
	
	/* Check if the file is correctly open */
	if (!input.is_open()) {
		std::cerr << "ERROR: There was a problem opening the input file!" << std::endl;
		return 1; /* exit */
	}
	
	/* Store file in a vector */
	double num = 0.0;
	while(input >> num){
		v.push_back(num);
	}
	
	/* Print vector*/
	PrintVector(v, "Data stored");
	
	/* Mean Value */
	mean = MeanVector(v);
	std::cout << "The mean value is: " << mean << std::endl;
	
	/* Median value */
	median = MedianVector(v);
	std::cout << "The median value is: " << median << std::endl;
	
	return 0;
}
/*********************************************************/

/*********************************************************/
template <typename T>
T MeanVector(const std::vector<T>& v){
	T sum = 0.0;
	T mean;
	
	for(auto x : v){
		sum += x;
	}
	
	mean = sum/(double)v.size();
	
	return mean;
}

/*********************************************************/
template <typename T>
T MedianVector(std::vector<T>& v){
	std::size_t size = v.size();
	
	/*Order vector*/
	std::sort(v.begin(), v.end());
	
	/* Median */
	if(size%2 == 0){
		return (v[size/2 - 1] + v[size/2])/2.0;
	}else{
		return v[size/2];
	}
}

/*********************************************************/
template <typename T>
void PrintVector(const std::vector<T>& v, const std::string& s) {
	std::cout << s << ": ";
	
	for (const auto& x : v){
		std::cout << x << " ";
	}
	
	std::cout << std::endl;
}