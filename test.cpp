/* Nithisha Sathishkumar
* October 13, 2023
* Project 1
* Professor.Dimpsey
*/

#include "time_span.h"
#include "time_span.cpp"
#include <iostream>
#include <sstream>

using namespace std;

bool CheckValues(TimeSpan time, int hours, int minutes, int seconds) {
  if ((time.hours() != hours) || (time.minutes() != minutes) ||
      (time.seconds() != seconds)) {
    return false;
  }
  return true;
}

bool TestZeros() {
  TimeSpan ts(0, 0, 0);
  return CheckValues(ts, 0, 0, 0);
}

bool TestThreeValue() {
  TimeSpan ts(1.5, 4, -10);
  return CheckValues(ts, 1, 33, 50);
}

bool TestTwoValue() {
  TimeSpan ts(7, -3);
  return CheckValues(ts, 0, 6, 57);
}

bool TestOneValue() {
  TimeSpan ts(-190);
  return CheckValues(ts, 0, -3, -10);
}

bool TestZeroSecondsOutput() {
  TimeSpan ts(3, -90, 120);
  return CheckValues(ts, 1, 32, 0);
}

bool TestFloatSeconds() {
  TimeSpan ts(127.86);
  return CheckValues(ts, 0, 2, 8);
}

bool TestNegativeFloat() {
  TimeSpan ts1(-6.249728, -23.196872, -4);
  if (CheckValues(ts1, -6, -38, -15)) {
    return true;
  } else {
    return false;
  }
}

bool TestIntValue() {
  TimeSpan ts1(23, 59, 60);
  if (CheckValues(ts1, 24, 0, 0)) {
    return true;
  } else {
    return false;
  }
}
bool TestFloatPositiveMinute() {
  TimeSpan ts1(23.43, 12.0);
  return CheckValues(ts1, 0, 23, 38);
}

bool TestThreeFloatValue() {
  TimeSpan ts1(.39245, 40.5844, 23.4901);
  return CheckValues(ts1, 1, 4, 31);
}

bool TestAdd() {
  TimeSpan ts1, ts2(5), ts3(7, 0), ts4(4, 0, 0);
  TimeSpan add_it_up = ts1 + ts2 + ts3 + ts4;
  return CheckValues(add_it_up, 4, 7, 5);
}

bool TestSubtract() {
  TimeSpan ts1(40), ts2(15);
  TimeSpan sub_it_up = ts1 - ts2;
  return CheckValues(sub_it_up, 0, 0, 25);
}

bool TestEqual() {
  TimeSpan ts1(-190);
  TimeSpan ts2(0, -3, -10);

  if (!CheckValues(ts1, 0, -3, -10)) {
    return false;
  }

  if (ts1 == ts2) {
    return true;
  } else {
    return false;
  }
}

bool TestNotEqual() {
  TimeSpan ts1(127.86);
  TimeSpan ts2(1, 3, 10);
  if (!CheckValues(ts1, 0, 2, 8)) {
    return false;
  }

  if (ts1 != ts2) {
    return true;
  } else {
    return false;
  }
}

bool TestUnaryNegationZero() {
  TimeSpan ts1(0, 0, 0);
  TimeSpan sign_change = -(ts1);
  return CheckValues(sign_change, -0, -0, -0);
}

bool TestUnaryNegationNegativeMinute() {
  TimeSpan ts1(3, -90, 120);
  TimeSpan sign_change = -(ts1);
  return CheckValues(sign_change, -1, -32, -0);
}

bool TestNegativeMinute() {
  TimeSpan ts(8, -23, 0);
  return CheckValues(ts, 7, 37, 0);
}

bool TestNegativeHour() {
  TimeSpan ts(-3, 73, 2);
  return CheckValues(ts, -1, -46, -58);
}

//  t1 > t2
bool TestMorethan() {
  TimeSpan ts1(1.5, 4, -10);
  TimeSpan ts2(0, 10, 20);
  if (!CheckValues(ts1, 1, 33, 50)) {
    return false;
  }
  if (ts1 > ts2) {
    return true;
  } else {
    return false;
  }
}

//  t1 < t2
bool TestLessthan() {
  TimeSpan ts1(127.86);
  TimeSpan ts2(0, 10, 20);
  if (!CheckValues(ts1, 0, 2, 8)) {
    return false;
  }
  if (ts1 < ts2) {
    return true;
  } else {
    return false;
  }
}

//  t1 <= t2
bool TestLessThanEqualTo() {
  TimeSpan ts1(1.5, 4, -10);
  TimeSpan ts2(1, 36, 55);

  if (!CheckValues(ts1, 1, 33, 50)) {
    return false;
  }
  if (ts1 <= ts2) {
    return true;
  } else {
    return false;
  }
}

//  t1 >= t2
bool TestMoreThanEqualTo() {
  TimeSpan ts1(1.5, 4, -10);
  TimeSpan ts2(1, 10, 20);
  if (!CheckValues(ts1, 1, 33, 50)) {
    return false;
  }
  if (ts1 >= ts2) {
    return true;
  }
  return false;
}

bool TestAddInPlace() {
  TimeSpan ts1(5, 6, 7);
  TimeSpan ts2(1, 1, 1);
  if ((!CheckValues(ts1, 5, 6, 7)) || (!CheckValues(ts2, 1, 1, 1))) {
    return false;
  }

  ts1 += ts2;
  if ((!CheckValues(ts1, 6, 7, 8)) || (!CheckValues(ts2, 1, 1, 1))) {
    return false;
  }
  return true;
}

bool TestSubtractInPlace() {
  TimeSpan ts1(5, 6, 7);
  TimeSpan ts2(1, 1, 1);
  if ((!CheckValues(ts1, 5, 6, 7)) || (!CheckValues(ts2, 1, 1, 1))) {
    return false;
  }

  ts1 -= ts2;
  if ((!CheckValues(ts1, 4, 5, 6)) || (!CheckValues(ts2, 1, 1, 1))) {
    return false;
  }
  return true;
}

bool TestSet_time() {
  TimeSpan t1;
  t1.set_time(1, 2, 3);
  if (t1.hours() != 1 || t1.minutes() != 2 || t1.seconds() != 3)
    return false;
  return true;
}

bool TestInsertionExtraction() {
  stringstream stream1;
  stringstream stream2;

  TimeSpan ts1;
  cout << "Enter Hour Minutes Seconds with space: ";
  cin >> ts1;

  stream1 << ts1;
  stream2 << "Hours: " << ts1.hours() << ", Minutes: " << ts1.minutes()
          << ", Seconds: " << ts1.seconds() << endl;

  if (stream1.str() == stream2.str()) {
    return true;
  } else {
    return false;
  }
}

int main() {
  const int kNumTests = 26;
  int test_passed = 0;

  //checks if the value of cout are printed in right form
  TimeSpan duration1(1, 2, 3);
  cout << duration1 << endl;

  if (!TestInsertionExtraction()) {
    cout << "\nFailed: Test Insertion Extraction" << endl;
  } else {
    cout << "\nTest Insertion Extraction passed" << endl;
    test_passed++;
  }

  if (!TestZeros()) {
    cout << "Failed: Test Zeros" << endl;
  } else {
    cout << "\nTest Zeros passed" << endl;
    test_passed++;
  }

  if (!TestThreeValue()) {
    cout << "Failed: Test ThreeValue" << endl;
  } else {
    cout << "\nTest ThreeValue passed" << endl;
    test_passed++;
  }

  if (!TestTwoValue()) {
    cout << "Failed: Test TwoValue" << endl;
  } else {
    cout << "\nTest TwoValue passed" << endl;
    test_passed++;
  }
  if (!TestOneValue()) {
    cout << "Failed: Test OneValue" << endl;
  } else {
    cout << "\nTest OneValue passed" << endl;
    test_passed++;
  }

  if (!TestZeroSecondsOutput()) {
    cout << "Failed: Test NoSeconds" << endl;
  } else {
    cout << "\nTest NoSeconds passed" << endl;
    test_passed++;
  }

  if (!TestFloatSeconds()) {
    cout << "Failed: Test FloatSeconds" << endl;
  } else {
    cout << "\nTest FloatSeconds passed" << endl;
    test_passed++;
  }

  if (!TestNegativeMinute()) {
    cout << "Failed: Test NegativeMinute" << endl;
  } else {
    cout << "\nTest negative minus passed" << endl;
    test_passed++;
  }

  if (!TestNegativeHour()) {
    cout << "\nFailed: Test NegativeHour" << endl;
  } else {
    cout << "\nTest negative hour passed" << endl;
    test_passed++;
  }

  if (!TestAdd()) {
    cout << "\nFailed: Test Add" << endl;
  } else {
    cout << "\nTest add is passed" << endl;
    test_passed++;
  }

  if (!TestSubtract()) {
    cout << "\nFailed: Test Subtract" << endl;
  } else {
    cout << "\nTest subtract is passed" << endl;
    test_passed++;
  }

  if (!TestUnaryNegationZero()) {
    cout << "\nFailed: Test UnaryNegation" << endl;
  } else {
    cout << "\nTest UnaryNegation is passed" << endl;
    test_passed++;
  }

  if (!TestUnaryNegationNegativeMinute()) {
    cout << "\nFailed: Test UnaryNegation NegativeMinute" << endl;
  } else {
    cout << "\nTest UnaryNegation NegativeMinute is passed" << endl;
    test_passed++;
  }

  if (!TestEqual()) {
    cout << "Failed: Test Equal" << endl;
  } else {
    cout << "\nTest Equal passed" << endl;
    test_passed++;
  }

  if (!TestNotEqual()) {
    cout << "Failed: Test Not Equal" << endl;
  } else {
    cout << "\nTest NotEqual passed" << endl;
    test_passed++;
  }

  if (!TestAddInPlace()) {
    cout << "Failed: Test AddInPlace" << endl;
  } else {
    cout << "\nTest AddInPlace passed" << endl;
    test_passed++;
  }

  if (!TestSubtractInPlace()) {
    cout << "Failed: Test AddInPlace" << endl;
  } else {
    cout << "\nTest AddInPlace passed" << endl;
    test_passed++;
  }

  if (!TestLessthan()) {
    cout << "Failed: Test LessThan" << endl;
  } else {
    cout << "\nTest LessThan passed" << endl;
    test_passed++;
  }

  if (!TestLessThanEqualTo()) {
    cout << "Failed: Test LessThanEqualTo" << endl;
  } else {
    cout << "\nTest LessThanEqualTo passed" << endl;
    test_passed++;
  }

  if (!TestMorethan()) {
    cout << "\nFailed: Test Morethan" << endl;
  } else {
    cout << "\nTest Morethan passed" << endl;
    test_passed++;
  }

  if (!TestMoreThanEqualTo()) {
    cout << "\nFailed: Test MoreThanEqualTo" << endl;
  } else {
    cout << "\nTest MoreThanEqualTo passed" << endl;
    test_passed++;
  }

  if (!TestSet_time()) {
    cout << "\nFailed: Test Set Time" << endl;
  } else {
    cout << "\nTest Set Time passed" << endl;
    test_passed++;
  }

  if (!TestNegativeFloat()) {
    cout << "\nFailed: Test Negative Float" << endl;
  } else {
    cout << "\nTest Negative Float passed" << endl;
    test_passed++;
  }

  if (!TestIntValue()) {
    cout << "\nFailed: Test Int Value" << endl;
  } else {
    cout << "\nTest Int Value passed" << endl;
    test_passed++;
  }
  if(!TestFloatPositiveMinute()) {
    cout << "\nFailed: Test Float Positive Minute" << endl;
    } else {
      cout << "\nTest Float Positive Minute passed" << endl;
      test_passed++;
  }

if(!TestThreeFloatValue()) {
    cout << "\nFailed: Test Three Float Value" << endl;
    } else {
      cout << "\nTest Three Float Value passed" << endl;
      test_passed++;
  }

  cout << "Total Tests Passed: " << test_passed << " of " << kNumTests << endl;
  return 0;
}