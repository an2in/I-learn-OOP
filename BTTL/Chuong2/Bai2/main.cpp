#include "DayPhanSo.h"
#include <iostream>

using namespace std;

int main() {
  DayPhanSo dayPS;
  dayPS.nhap();
  cout << "\nDay phan so vua nhap: ";
  dayPS.xuat();
  cout << "Tong cac phan so: ";
  dayPS.tinhTong().xuat();
  cout << "\nPhan so lon nhat: ";
  dayPS.timMax().xuat();
  cout << "\n";

  return 0;
}
