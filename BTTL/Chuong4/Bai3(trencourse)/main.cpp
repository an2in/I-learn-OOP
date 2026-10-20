#include "DonThuc.h"
#include <iostream>

using namespace std;

int main() {
  DonThuc d1, d2;

  cout << "=== Nhap don thuc 1 ===\n";
  d1.nhap();

  cout << "\n=== Nhap don thuc 2 ===\n";
  d2.nhap();

  cout << "\nDon thuc 1: ";
  d1.xuat();
  cout << "\nDon thuc 2: ";
  d2.xuat();

  cout << "\n\nTong 2 don thuc: ";
  DonThuc tong = d1.cong(d2);
  tong.xuat();
  cout << "\n";

  // Test dao ham:D
  cout << "Dao ham don thuc 1: ";
  d1.tinhDaoHam().xuat();
  cout << "\n";

  double x;
  cout << "Nhap x de tinh gia tri don thuc 1: ";
  cin >> x;
  cout << "Gia tri don thuc 1 tai x = " << x << " la: " << d1.tinhGiaTri(x)
       << "\n";

  return 0;
}
