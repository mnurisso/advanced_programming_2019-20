#include <iostream>

/* ********************************************************************* */
class Date{
  unsigned int _day;
  //enum _month {jan, feb, mar, apr, may, jun, jul, aug,
  //                  sept, oct, nov, dec};
  unsigned int _year;
  
  public:
    void Day();
    //void Month();
    void Year();
    Date(unsigned int day, unsigned int year); // constructor
};

/* ********************************************************************* */
int main() {
/*! 
 * Main to use the Date class
 *********************************************************************** */
  Date birth{29, 1992};
  
  birth.Day();
  birth.Year();
  return 0;
}

/* ********************************************************************* */
void Date::Day(){
  std::cout << "The day is: " << Date::_day << std::endl;
}

///* ********************************************************************* */
//void Date::Month(){
//  std::cout << "The month is: " << Date::_month << std::endl;
//}

/* ********************************************************************* */
void Date::Year(){
  std::cout << "The day is: " << Date::_year << std::endl;
}

Date::Date(unsigned int day, unsigned int year)
  : _day{day},
    //_month{month},
    _year{year}
{
  std::cout << "Custom constructor" << std::endl;
}