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
  
  birth.PrintDay();
  birth.PrintMonth();
  birth.PrintYear();
  
  unsigned int n = 3;
  
  std::cout << "Adding " << n << " days:" << std::endl;
  
  birth.AddDays(n);
  
  std::cout << "The new day is:" << std::endl;
  
  birth.PrintDay();
  birth.PrintMonth();
  birth.PrintYear();
  
  std::cout << "Try << substitution for Date class:" << std::endl;
  std::cout << birth << std::endl;
  
  return 0;
}