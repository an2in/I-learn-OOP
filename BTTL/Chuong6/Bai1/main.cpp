#include "CBVC.h"
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  QuanLyCBVC ql;

  cout << "=== NHAP DANH SACH CAN BO VIEN CHUC ===\n";
  ql.nhap();

  cout << "\n=== DANH SACH CAN BO VIEN CHUC VA TIEN LUONG ===\n";
  ql.xuat();

  cout << "\nTong chi tra luong cho CBVC: " << fixed << setprecision(0)
       << ql.tinhTongLuong() << " VND\n";

  return 0;
}
