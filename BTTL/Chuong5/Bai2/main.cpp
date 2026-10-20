#include "DSPhanSo.h"
#include <iostream>

using namespace std;

int main() {
  DSPhanSo ds;
  ds.Nhap();

  cout << "\nDanh sach phan so vua nhap: ";
  ds.Xuat();

  PhanSo maxPS = ds.TimMax();
  cout << "Phan so co gia tri lon nhat: ";
  maxPS.Xuat();
  cout << endl;

  PhanSo tong = ds.TinhTong();
  cout << "Tong cac phan so: ";
  tong.Xuat();
  cout << endl;

  return 0;
}
