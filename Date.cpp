#include <ctime>

using namespace std;

#include "Date.h"
#include "config.h"

bool Date::isLeapYear(int year) {
    return (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0));

}

int Date::daysInMonth(int month, int year) {
    switch (month)
    {
    case 2:
        if (isLeapYear(year))
            return 29;
        else
            return 28;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
        break;
    default:
        return 31;
        break;
    }

}

Date::Date() {
    time_t now = time(NULL);
    struct tm *current = localtime(&now);

    day = current->tm_mday;
    month = current->tm_mon + 1;
    year = current->tm_year + 1900;
}

Date::Date(int day_, int month_, int year_) throw (logic_error)
    : day(day_), month(month_), year(year_)
{
    if (month <= 0) {
	throw logic_error("Month too low.");
    }
    if (month > 12) {
	throw logic_error("Month too high.");
    }

    if (day <= 0) {
	throw logic_error("Day too low.");
    }
    if (day > daysInMonth(month, year)) {
	throw logic_error("Day too high.");
    }

    // no check on year?
}

#if LAB2_TEST9
int Date::getDayOfWeek() const {
    // inefficient, but accurate
    
}
#endif

int Date::getDay() const {
    return day;

}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}

void Date::showStructure() const {
    // Outputs data in same form as operator<<.
    // NOTE: could do "cout << *this << endl", but that would not compile
    // if operator<< has not been defined.
	cout << *this << endl;
    
}

#if LAB2_TEST10
bool Date::operator<(const Date& rhs) const {
    
}

bool Date::operator==(const Date& rhs) const {
    
}

bool Date::operator>(const Date& rhs) const {

}
#endif

ostream& operator<<(ostream& out, const Date& date) {
    
   return out << date.month << "/" << date.day << "/" << date.year << endl;
}
