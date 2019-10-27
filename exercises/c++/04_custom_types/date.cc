#include <iostream>

/* ********************************************************************* */
class Date{
  public:
    enum class Month {jan, feb, mar, apr, may, jun, jul, aug,
                      sept, oct, nov, dec};
  private:
    unsigned int _day;
    Month _month;
    unsigned int _year;
    void AddDay();
  
  public:
    void AddDays(const unsigned int n);
    void PrintDay();
    void PrintMonth();
    void PrintYear();
    Date(unsigned int day, Month month, unsigned int year);
};

std::ostream& operator<<(std::ostream& os, const Date::Month& month);
//std::ostream& operator<<(std::ostream& os, const Date& d);

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
  
  return 0;
}

/* ********************************************************************* */
void Date::PrintDay(){
  std::cout << "The day is: " << Date::_day << std::endl;
}

/* ********************************************************************* */
void Date::PrintMonth(){
  std::cout << "The month is: " << Date::_month << std::endl;
}

/* ********************************************************************* */
void Date::PrintYear(){
  std::cout << "The year is: " << Date::_year << std::endl;
}

/* ********************************************************************* */
Date::Date(unsigned int day, Month month, unsigned int year)
  : _day{day},
    _month{month},
    _year{year}
{
  std::cout << "Custom constructor" << std::endl;
}

/* ********************************************************************* */
//  28 feb
//  30 apr jun sept nov
//  31 jan mar may jul aug oct dec
/* ********************************************************************* */
void Date::AddDay(){
  switch(_month){
    case Month::jan:{
      if(_day==31){
        _month = Month::feb;
        _day = 1;
      }else{++_day;}
      break;
    }
    case Month::feb:{
      if(_day==28){
        _month = Month::mar;
        _day = 1;
      }else{++_day;}
      break;
    }
    case Month::mar:{
      if(_day==31){
        _month = Month::apr;
        _day = 1;
      }else{++_day;}
      break;
    }
    case Month::apr:{
      if(_day==30){
        _month = Month::may;
        _day = 1;
      }else{++_day;}
      break;
    }
    case Month::may:{
      if(_day==31){
        _month = Month::jun;
        _day = 1;
      }else{++_day;}
      break;
    }
    case Month::jun:{
      if(_day==30){
        _month = Month::jul;
        _day = 1;
      }else{++_day;}
      break;
    }
    case Month::jul:{
      if(_day==31){
        _month = Month::aug;
        _day = 1;
      }else{++_day;}
      break;
    }
    case Month::aug:{
      if(_day==31){
        _month = Month::sept;
        _day = 1;
      }else{++_day;}
      break;
    }
    case Month::sept:{
      if(_day==30){
        _month = Month::oct;
        _day = 1;
      }else{++_day;}
      break;
    }
    case Month::oct:{
      if(_day==31){
        _month = Month::nov;
        _day = 1;
      }else{++_day;}
      break;
    }
    case Month::nov:{
      if(_day==30){
        _month = Month::dec;
        _day = 1;
      }else{++_day;}
      break;
    }
    case Month::dec:{
      if(_day==31){
        _month = Month::jan;
        _day = 1;
        ++_year;
      }else{++_day;}
      break;
    }
  }

}

/* ********************************************************************* */
void Date::AddDays(const unsigned int n){
  for(unsigned int i=0; i<n; i++){
    Date::AddDay();
  }
}

/* ********************************************************************* */
std::ostream& operator<<(std::ostream& os, const Date::Month& month){
    switch(month) {
    case Date::Month::jan: os << "Jan"; break;
    case Date::Month::feb: os << "Feb"; break;
    case Date::Month::mar: os << "Mar"; break;
    case Date::Month::apr: os << "Apr"; break;
    case Date::Month::may: os << "May"; break;
    case Date::Month::jun: os << "Jun"; break;
    case Date::Month::jul: os << "Jul"; break;
    case Date::Month::aug: os << "Aug"; break;
    case Date::Month::sept: os << "Sept"; break;
    case Date::Month::oct: os << "Oct"; break;
    case Date::Month::nov: os << "Nov"; break;
    case Date::Month::dec: os << "Dec"; break;
    }
    return os;
}

///* ********************************************************************* */
//std::ostream& operator<<(std::ostream& os, const Date& d){
//  d.PrintDay();
//  //d.PrintMonth();
//  //d.PrintYear();
//  return os;
//}