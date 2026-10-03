#include "cHocSinh.h"
#include <iostream>

using namespace std;

int main() {
  cHocSinh hs1, hs2;
  hs1.nhap();
  hs2.nhap();

  hs1.xuat();
  hs2.xuat();

  if (hs1.getDiemTB() > hs2.getDiemTB()) {
    cout << "Hoc sinh co diem trung binh cao hon: " << hs1.getHoTen() << "\n";
  } else if (hs2.getDiemTB() > hs1.getDiemTB()) {
    cout << "Hoc sinh co diem trung binh cao hon: " << hs2.getHoTen() << "\n";
  } else {
    cout << "Hai hoc sinh co diem trung binh bang nhau.\n";
  }

  if (hs1.getNamSinh() > hs2.getNamSinh()) {
    cout << "Hoc sinh co tuoi nho hon: " << hs1.getHoTen() << "\n";
  } else if (hs2.getNamSinh() > hs1.getNamSinh()) {
    cout << "Hoc sinh co tuoi nho hon: " << hs2.getHoTen() << "\n";
  } else {
    cout << "Hai hoc sinh bang tuoi nhau.\n";
  }

  return 0;
}
