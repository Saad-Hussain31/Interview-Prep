/*
first iter can go after last iter, so always check the validity of iters like
[ first != vec.end() && last != vec.end() ]

before derefencing last iter, check if its valid or not [ last != vec.end() ]

vec.end() returns a temp object and in C++ its illegal to modify temp objs, so
you cant do --vec.end() to get the last iterator. [ e.end() - 1 ]will work. for
ref, watch Luv's map video

1. Valid values: Is the iterator dereferenceable? For example, writing
"*e.end()" is always a programming error.

2. Valid lifetimes: Is the iterator still valid when it's being used? Or has it
been invalidated by some operation since we obtained it?

3. Valid ranges: Is a pair of iterators a valid range? Is first really before
(or equal to) last? Do both really point into the same container?

4. Illegal builtin manipulation: For example, is the code trying to modify a
temporary of builtin type, as in
"--e.end()" above? (Fortunately, the compiler can often catch this kind of
mistake for you, and for iterators of class type, the library author will often
choose to allow this sort of thing for syntactic convenience.)

*/

#include <algorithm>
#include <chrono>
#include <ctime>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

struct Date {
  int day, month, year;

  Date() : day(0), month(0), year(0) {}
  Date(int d, int m, int y) : day(d), month(m), year(y) {}

  friend istream &operator>>(istream &is, Date &d) {
    is >> d.day >> d.month >> d.year;
    return is;
  }

  Date &operator=(const char *dateStr) {
    // Example conversion from the string format "mm/dd/yy" to integer values
    sscanf(dateStr, "%d/%d/%d", &month, &day, &year);
    return *this;
  }

  bool operator==(const char *dateStr) const {
    Date temp;
    // Example conversion from the string format "mm/dd/yy" to integer values
    sscanf(dateStr, "%d/%d/%d", &temp.month, &temp.day, &temp.year);
    return (day == temp.day && month == temp.month && year == temp.year);
  }

  friend ostream &operator<<(ostream &os, const Date &d) {
    os << d.month << "/" << d.day << "/" << d.year;
    return os;
  }
};

Date TodaysDate() {

  auto now = chrono::system_clock::now();
  time_t now_time = chrono::system_clock::to_time_t(now);
  struct tm *current_time = localtime(&now_time);

  int currentDay = current_time->tm_mday;
  int currentMonth = current_time->tm_mon + 1;    // tm_mon is 0-indexed
  int currentYear = current_time->tm_year + 1900; // tm_year is years since 1900

  return Date(currentDay, currentMonth, currentYear);
}

int main() {
  vector<Date> vec;
  cout << "Enter dates (day month year):" << endl;

  istream_iterator<Date> beginIt(cin); // operator>> is implicitly called here
  istream_iterator<Date> endIt;

  copy(istream_iterator<Date>(beginIt), endIt, back_inserter(vec));

  vector<Date>::iterator first = find(vec.begin(), vec.end(), "01/01/24");
  vector<Date>::iterator last = find(vec.begin(), vec.end(), "12/31/24");

  if (last !=
      vec.end()) {      // Safety check for last not being next to end iterator
    *last = "12/30/95"; // Modify the date pointed to by last
  } else {
    // Handle the case where "12/31/95" is not found in the vector
    cout << "Date not found in the vector." << endl;
  }

  // Check if both first and last are valid iterators within the range of vec
  if (first != vec.end() && last != vec.end()) {
    // copy if both first and last are valid
    copy(first, last, ostream_iterator<Date>(cout, "\n"));
  } else {
    // case where one or both of the dates are not found in vec
    cout << "One or both of the dates are not found in the vector." << endl;
  }

  vec.insert(--vec.end(), TodaysDate());

  // Reacquire iterators after the insert operation coz older ones maybe
  // invalidated due to vector reallocation
  first = vec.begin();
  last = vec.end();

  copy(first, last, ostream_iterator<Date>(cout, "\n"));
}