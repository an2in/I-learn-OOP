#include "NhanVien.h"
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  CongTyABC cty;

  cout << "=== QUAN LY NHAN VIEN CONG TY ABC (THU NHOI BONG) ===\n";
  cty.nhap();

  cout << "\n=== THONG TIN VA TIEN LUONG CUA CAC NHAN VIEN ===\n";
  cty.xuat();

  cout << "\nTong luong toan cong ty: " << fixed << setprecision(0)
       << cty.tinhTongLuong() << " VND\n";

  string tenTimKiem;
  cout << "\nNhap ho ten nhan vien can tim: ";
  getline(cin >> ws, tenTimKiem);
  cty.timKiemTheoTen(tenTimKiem);

  return 0;
}
