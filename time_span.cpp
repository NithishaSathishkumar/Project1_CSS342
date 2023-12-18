/* Nithisha Sathishkumar
* October 13, 2023
* Project 1
* Professor.Dimpsey
*/

#include "time_span.h"
#include <cmath> //rounding function
#include <iostream> 

using namespace std;

// constructors
TimeSpan::TimeSpan() {
  this->hour_ = 0;
  this->minute_ = 0;
  this->second_ = 0;
}

TimeSpan::TimeSpan(double second){ 
  FormateTime(0, 0, second); 
}

TimeSpan::TimeSpan(double minute, double second){
  FormateTime(0, minute, second);
}

TimeSpan::TimeSpan(double hour, double minute, double second) {
  FormateTime(hour, minute, second);
}

//settter set_time
void TimeSpan::set_time(int hours, int minutes, int seconds) {
  this->hour_ = hours;
  this->minute_ = minutes;
  this->second_ = seconds;
}

//formate time
void TimeSpan::FormateTime(double hour, double minute, double second) {
  this->hour_ = 0;
  this->minute_ = 0;
  this->second_ = 0;

  //converting all the value to seconds
  this->second_ = round((hour * 3600) + (minute * 60) + second);

  //formating the hour_, minute_, second_;
  this->minute_ = this->second_ / 60;
  this->second_ = this->second_ % 60;
  this->hour_ = this->minute_ / 60;
  this->minute_ = this->minute_ % 60;
  
}

//getters
int TimeSpan::hours() const {
  return this->hour_; 
}

int TimeSpan::minutes() const { 
  return this->minute_; 
}

int TimeSpan::seconds() const { 
  return this->second_; 
}


//overload Math operation
//Addition
TimeSpan TimeSpan::operator+(TimeSpan const &right) {
  TimeSpan result;
  result.second_ = this->second_ + right.second_;
  result.minute_ = this->minute_ + right.minute_;
  result.hour_ = this->hour_ + right.hour_;
  result.FormateTime(result.hour_, result.minute_, result.second_);
  return result;
}

//Subtraction
TimeSpan TimeSpan::operator-(TimeSpan const &right) {
  TimeSpan result;
  result.second_ = this->second_ - right.second_;
  result.minute_ = this->minute_ - right.minute_;
  result.hour_ = this->hour_ - right.hour_;
  result.FormateTime(result.hour_, result.minute_, result.second_);
  return result;
}

//unary negation 
TimeSpan TimeSpan::operator-() {
  TimeSpan result;
  result.second_ = -(this->second_);
  result.minute_ = -(this->minute_);
  result.hour_ = -(this->hour_);
  return result;
}

//overload comparsion operation
//Equal to
bool TimeSpan::operator==(TimeSpan const &right) const {
  if (this->hour_ == right.hour_ && this->minute_ == right.minute_ && this->second_ == right.second_) {
    return true;
  } else {
    return false;
  }
}

//Not Equal to
bool TimeSpan::operator!=(TimeSpan const &right) const {
  if (this->hour_ != right.hour_ && this->minute_ != right.minute_ && this->second_ != right.second_) {
    return true;
  } else {
    return false;
  }
}

// left < right
bool TimeSpan::operator<(TimeSpan const &right) const {
  if (this->hour_ < right.hour_) {
    return true;
  } else if (this->hour_ == right.hour_ && this->minute_ < right.minute_) {
    return true;
  } else if (this->hour_ == right.hour_ && this->minute_ == right.minute_ && this->second_ < right.second_) {
    return true;
  } else {
    return false;
  }
}

// left >= right
bool TimeSpan::operator>=(TimeSpan const &right) const {
  if (*this > right || *this == right) {
    return true;
  } else {
    return false;
  }
}

// left > right
bool TimeSpan::operator>(TimeSpan const &right) const {
  if (this->hour_ > right.hour_) {
    return true;
  } else if (this->hour_ == right.hour_ && this->minute_ > right.minute_) {
    return true;
  } else if (this->hour_ == right.hour_ && this->minute_ == right.minute_ && this->second_ > right.second_) {
    return true;
  } else {
    return false;
  }
}

// left <= right
bool TimeSpan::operator<=(TimeSpan const &right) const { 
  if (*this < right || *this == right) {
    return true;
  } else {
    return false;
  }
}

//assignment statement
TimeSpan TimeSpan::operator+=(TimeSpan const &right) {
  this->second_ += right.second_;
  this->minute_ += right.minute_;
  this->hour_ += right.hour_;
  FormateTime(this->hour_, this->minute_, this->second_);
  return *(this);
}

TimeSpan TimeSpan::operator-=(TimeSpan const &right) {
  this->second_ -= right.second_;
  this->minute_ -= right.minute_;
  this->hour_ -= right.hour_;
  FormateTime(this->hour_, this->minute_, this->second_);
  return *(this);
}

// stream I/O
//Input operator
istream &operator>>(istream &cin, TimeSpan &right) {
  cin >> right.hour_ >> right.minute_ >> right.second_;
  return cin;
}

//Output opertor
ostream &operator<<(ostream &cout, const TimeSpan &right) {
  cout << "Hours: " << right.hours() << ", Minutes: " << right.minutes()
       << ", Seconds: " << right.seconds() << endl;
  return cout;
}


