#include "PhanSo.h"
#include <iostream>

using namespace std;

int main() {
  PhanSo ps1, ps2;
  ps1.nhap();
  ps2.nhap();
  cout << "Phan so 1: ";
  ps1.xuat();
  cout << "\nPhan so 2: ";
  ps2.xuat();
  cout << "\nTong: ";
  ps1.cong(ps2).xuat();
  cout << "\nHieu: ";
  ps1.tru(ps2).xuat();
  cout << "\nTich: ";
  ps1.nhan(ps2).xuat();
  cout << "\nThuong: ";
  ps1.chia(ps2).xuat();

  return 0;
}
