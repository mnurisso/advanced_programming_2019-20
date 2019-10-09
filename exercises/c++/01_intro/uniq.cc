#include <algorithm> //to set vector to the same value
#include <iostream>  //std::cout
#include <fstream>   //std::ifstream
#include <sstream>
#include <string>

int main (){
	/* Variables */
	int nol; 	// number of lines
	std::string filename;
	std::string line;
	
	/* 1. Asking for the filename */
	std::cout << "> Insert a textfile name:" << std::endl;
	std::cin >> filename;
	std::ifstream myfile(filename);
	
	/* 2. Read file line by line */
	if(myfile.is_open()){
		
		/* 2.1 Counting the number of lines*/
		for(std::string line; std::getline(myfile,line);){
			++nol;
		}
		std::cout << "> Open file " << filename	<< ":" << std::endl;
		std::cout << "> Number of lines in text file: " << nol << std::endl<< std::endl;
		
		/* 2.2 String array */
		std::string filearray[nol];
		int rep[nol];
		std::fill_n(rep,nol,1);
		
		/* 2.3 Go back to the beginning of the file */
		myfile.clear();
		myfile.seekg(0, std::ios::beg);
		
		/* 2.4 Comparison between lines */
		for(int i=0;i<nol;i++){
			getline(myfile,line);
			filearray[i] = line;
			for(int j=0; j<=i; j++){
				if(i==j) continue;
				else{
					/* Updating number counts and deleting i line */
					if(filearray[i] == filearray[j]){
						++rep[j]; 
					}
				}
			}
		}
		
		/* 2.5 Print the new file */
		for(int i=0;i<nol;i++){
			std::cout << rep[i] << " " << filearray[i] << std::endl;
		}
		
		//for(std::string line; getline(myfile,line);){
		//	file
		//	std::cout << line	<< std::endl;
		//	++ln;
		//}
	}else{
		std::cout << "> Error: " <<filename << " doesn't exist." << std::endl;
	}
	return 0;
}