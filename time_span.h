/* Nithisha Sathishkumar
* October 13, 2023
* Project 1
* Professor.Dimpsey
*/

#ifndef TIME_SPAN_H_
#define TIME_SPAN_H_
#include <iostream>

using namespace std;

class TimeSpan {
public:
  // 4 constructors
  TimeSpan();
  TimeSpan(double second);
  TimeSpan(double minute, double second);
  TimeSpan(double hour, double minute, double second);

  // formate the time
  void FormateTime(double hour, double minute, double second);

  //setter
  void set_time(int hours, int minutes, int seconds);

  // getter
  int hours() const;
  int minutes() const;
  int seconds() const;

  // overload Math operation
  TimeSpan operator+(TimeSpan const &t1);
  TimeSpan operator-(TimeSpan const &other);
  TimeSpan operator-();

  // overload comparsion operation
  bool operator==(TimeSpan const &other) const;
  bool operator!=(TimeSpan const &other) const;

  bool operator<(TimeSpan const &other) const;
  bool operator<=(TimeSpan const &other) const;
  bool operator>(TimeSpan const &other) const;
  bool operator>=(TimeSpan const &other) const;

  // assignment statement
  TimeSpan operator+=(TimeSpan const &other);
  TimeSpan operator-=(TimeSpan const &other);

  // stream I/O
  friend istream &operator>>(istream &cin, TimeSpan &other);
  friend ostream &operator<<(ostream &cout, const TimeSpan &other);
  
private:
  //private data members
  int hour_;
  int minute_;
  int second_;
};

#endif
