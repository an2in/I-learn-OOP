#include "SoPhuc.h"
#include <iostream>

using namespace std;

int main() {
  SoPhuc a, b;
  cout << "Nhap so phuc A:\n";
  cin >> a;
  cout << "Nhap so phuc B:\n";
  cin >> b;

  cout << "\nA = " << a << endl;
  cout << "B = " << b << endl;

  cout << "A + B = " << (a + b) << endl;
  cout << "A - B = " << (a - b) << endl;
  cout << "A * B = " << (a * b) << endl;
  cout << "A / B = " << (a / b) << endl;

  if (a == b) {
    cout << "A bang B\n";
  } else {
    cout << "A khong bang B\n";
  }

  return 0;
}
