#include "DaThuc.h"
#include <iostream>

using namespace std;

int main() {
  DaThuc p1, p2;
  cout << "--- Nhap da thuc P1 ---\n";
  cin >> p1;
  cout << "\n--- Nhap da thuc P2 ---\n";
  cin >> p2;

  cout << "\nP1(x) = " << p1 << endl;
  cout << "P2(x) = " << p2 << endl;

  DaThuc tong = p1 + p2;
  DaThuc hieu = p1 - p2;

  cout << "\nP1(x) + P2(x) = " << tong << endl;
  cout << "P1(x) - P2(x) = " << hieu << endl;

  double x;
  cout << "\nNhap gia tri x can tinh: ";
  cin >> x;
  cout << "P1(" << x << ") = " << p1.tinhGiaTri(x) << endl;
  cout << "P2(" << x << ") = " << p2.tinhGiaTri(x) << endl;

  return 0;
}
