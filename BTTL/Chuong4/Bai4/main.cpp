#include "DaThuc.h"
#include <iostream>

using namespace std;

int main() {
  DaThuc P1, P2;

  cout << "=== Nhap da thuc P1 ===\n";
  P1.nhap();

  cout << "\n=== Nhap da thuc P2 ===\n";
  P2.nhap();

  cout << "\nDa thuc P1: ";
  P1.xuat();
  cout << "\nDa thuc P2: ";
  P2.xuat();

  cout << "\n\nTong 2 da thuc (P1 + P2): ";
  DaThuc tong = P1.cong(P2);
  tong.xuat();

  cout << "\nHieu 2 da thuc (P1 - P2): ";
  DaThuc hieu = P1.tru(P2);
  hieu.xuat();
  cout << "\n";

  double x;
  cout << "\nNhap x de tinh gia tri cua da thuc P1: ";
  cin >> x;
  cout << "P1(" << x << ") = " << P1.tinhGiaTri(x) << "\n";

  return 0;
}
