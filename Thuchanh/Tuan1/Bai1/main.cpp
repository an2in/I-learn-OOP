#include "PhanSo.h"
#include <iostream>

using namespace std;

int main() {
  PhanSo a;
  PhanSo b;

  cout << "=== NHAP PHAN SO A ===\n";
  a.nhapPhanso();
  cout << "Phan so A vua nhap: ";
  a.inPhanSo();

  cout << "\n=== NHAP PHAN SO B ===\n";
  b.nhapPhanso();
  cout << "Phan so B vua nhap: ";
  b.inPhanSo();

  // Thuc hien phep cong
  PhanSo tong = a.CongPhanso(b);
  cout << "\nTong (A + B) da rut gon: ";
  tong.inPhanSo();

  // Thuc hien phep tru
  PhanSo hieu = a.TruPhanSo(b);
  cout << "Hieu (A - B) da rut gon: ";
  hieu.inPhanSo();

  return 0;
}
