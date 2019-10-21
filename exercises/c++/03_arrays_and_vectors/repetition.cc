#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
/*********************************************************/

template <typename T>
void PrintVector(const std::vector<T>& v, const std::string& s);

void RepetitionVector(std::vector<std::string>& v);

/*********************************************************/
int main(){
	std::vector<std::string> v;
	std::string line; /* Complete sentence */
	
	std::cout << "Enter words, one per line (leave an empty line when done)" << std::endl;
	
	while(std::getline(std::cin, line)){
		if(line.size()==0) break;
		
		std::istringstream iss(line);
		std::string word;
		if(!(iss>>word)) break;
		
		v.push_back(word);
	}
	
	PrintVector(v,"Initial sentence");
	
	RepetitionVector(v);
	
	PrintVector(v,"No repetitions");
	
	return 0;
}
/*********************************************************/

/*********************************************************/
template <typename T>
void PrintVector(const std::vector<T>& v, const std::string& s) {
	std::cout << s << ": ";
	
	for (const auto& x : v){
		std::cout << x << " ";
	}
	
	std::cout << std::endl;
}

/*********************************************************/
void RepetitionVector(std::vector<std::string>& v){
	/* Sort the vector */
	std::sort(v.begin(), v.end());
	
	/* Check for repetition */
	for (auto i = 0u; i < v.size(); ++i){
		for (auto j = i+1; j < v.size(); ++j){
			if(v[i].compare(v[j]) == 0){/* Strings are equal */
				v.erase(v.begin()+j);
			}
		}
	}
}