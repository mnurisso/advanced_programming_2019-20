#include <iostream>

/* ******************************************************************** *
 * Defining the class Date
 *
 * Attributes:
 *
 * - d Day
 * - m Month
 * - y Year
 *
 * Functions
 * Day() to access private attributes
 * Month()
 * Year()
 * ******************************************************************** */
//enum class Month {jan, feb, mar, apr, may, jun, jul, aug,
//                      sept, oct, nov, dec};
class Date{
  public:
    enum class Month {jan, feb, mar, apr, may, jun, jul, aug,
                      sept, oct, nov, dec};
  private:
    unsigned int d;
    Month m;
    unsigned int y;
    void AddDay();
  
  public:
    void AddDays(const unsigned int n);
    auto ReturnDay();
    auto ReturnMonth();
    auto ReturnYear();
    Date(unsigned int day, Month month, unsigned int year);
};

/* ******************************************************************** *
 * Function overload for  <<
 * ******************************************************************** */
std::ostream& operator<<(std::ostream& os, const Date::Month& m);
std::ostream& operator<<(std::ostream& os, Date& d);

/* ********************************************************************* */
auto Date::ReturnDay(){
  return d;
}

/* ********************************************************************* */
auto Date::ReturnMonth(){
  return m;
}

/* ********************************************************************* */
auto Date::ReturnYear(){
  return y;
}

/* ********************************************************************* */
Date::Date(unsigned int day, Month month, unsigned int year)
  : d{day},
    m{month},
    y{year}
{
  std::cout << "Custom constructor" << std::endl;
}

/* ********************************************************************* */
//  28 feb
//  30 apr jun sept nov
//  31 jan mar may jul aug oct dec
/* ********************************************************************* */
void Date::AddDay(){
  switch(m){
    case Month::jan:{
      if(d==31){
        m = Month::feb;
        d = 1;
      }else{++d;}
      break;
    }
    case Month::feb:{
      if(d==28){
        m = Month::mar;
        d = 1;
      }else{++d;}
      break;
    }
    case Month::mar:{
      if(d==31){
        m = Month::apr;
        d = 1;
      }else{++d;}
      break;
    }
    case Month::apr:{
      if(d==30){
        m = Month::may;
        d = 1;
      }else{++d;}
      break;
    }
    case Month::may:{
      if(d==31){
        m = Month::jun;
        d = 1;
      }else{++d;}
      break;
    }
    case Month::jun:{
      if(d==30){
        m = Month::jul;
        d = 1;
      }else{++d;}
      break;
    }
    case Month::jul:{
      if(d==31){
        m = Month::aug;
        d = 1;
      }else{++d;}
      break;
    }
    case Month::aug:{
      if(d==31){
        m = Month::sept;
        d = 1;
      }else{++d;}
      break;
    }
    case Month::sept:{
      if(d==30){
        m = Month::oct;
        d = 1;
      }else{++d;}
      break;
    }
    case Month::oct:{
      if(d==31){
        m = Month::nov;
        d = 1;
      }else{++d;}
      break;
    }
    case Month::nov:{
      if(d==30){
        m = Month::dec;
        d = 1;
      }else{++d;}
      break;
    }
    case Month::dec:{
      if(d==31){
        m = Month::jan;
        d = 1;
        ++y;
      }else{++d;}
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
    case Date::Month::jan:  os << "Jan";  break;
    case Date::Month::feb:  os << "Feb";  break;
    case Date::Month::mar:  os << "Mar";  break;
    case Date::Month::apr:  os << "Apr";  break;
    case Date::Month::may:  os << "May";  break;
    case Date::Month::jun:  os << "Jun";  break;
    case Date::Month::jul:  os << "Jul";  break;
    case Date::Month::aug:  os << "Aug";  break;
    case Date::Month::sept: os << "Sept"; break;
    case Date::Month::oct:  os << "Oct";  break;
    case Date::Month::nov:  os << "Nov";  break;
    case Date::Month::dec:  os << "Dec";  break;
    }
    return os;
}

/* ********************************************************************* */
std::ostream& operator<<(std::ostream& os, Date& d){
	os << "Day: " << d.ReturnDay() << " Month: " << d.ReturnMonth()
     << " Year: " << d.ReturnYear() << std::endl;
  
  return os;
}