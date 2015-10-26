#include <iostream>
using namespace std;

inline void f (int month, int year) {
  // Here is inline function
  cout << "month is " << month << endl;
  cout << "year is " << year << endl;
}
void g (int month, int year) {
  // Here is normal functions
  cout << "month is " << month << endl;
  cout << "year is " << year << endl;
}

int main()
{
  int month = 10, year = 2008;
  f (month, year);
  g (month, year);
  return 0;
}
