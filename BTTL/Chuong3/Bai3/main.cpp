#include "Diem.h"
#include <iostream>

using namespace std;

int main() {
  Diem d1, d2;
  cout << "Nhap diem thu nhat:\n";
  d1.nhap();
  cout << "Nhap diem thu hai:\n";
  d2.nhap();
  cout << "Diem 1: ";
  d1.xuat();
  cout << "\nDiem 2: ";
  d2.xuat();
  cout << "\nKhoang cach: " << d1.tinhKhoangCach(d2) << "\n";
  return 0;
}
