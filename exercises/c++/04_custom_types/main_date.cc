#include <iostream>
#include "date.h" 

/* ********************************************************************* */
int main() {
/*! 
 * Main to use the Date class
 *********************************************************************** */
  unsigned int day{29};
  Date::Month month{Date::Month::jul};
  unsigned int year{1992};
  
  Date birth{day, month, year};
  
  std::cout << "My birthday is:" << std::endl;
  std::cout << birth << std::endl;
  
  unsigned int n = 3;
  
  std::cout << "Adding " << n << " days:" << std::endl;
  
  birth.AddDays(n);
  
  std::cout << "The new day is:" << std::endl;
  std::cout << birth << std::endl;
 
  Date true_birth{day,month,year};
  
  std::cout << "The true day is:" << std::endl;
  std::cout << true_birth << std::endl;
  
  if(birth==true_birth){
    std::cout << "The two dates are equal" << std::endl;
  }else{
    std::cout << "The two dates are different" << std::endl;
  }
  
  if(birth!=true_birth){
    std::cout << "The two dates are different" << std::endl;
  }else{
    std::cout << "The two dates are equal" << std::endl;
  }
  
  return 0;
}