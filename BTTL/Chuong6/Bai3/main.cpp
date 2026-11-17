#include "NhanVien.h"
#include <iostream>

using namespace std;

int main() {
  CongTy cty;

  cout << "=== NHAP DANH SACH NHAN VIEN CONG TY HOAN CAU ===\n";
  cty.nhap();

  cout << "\n=== DANH SACH NHAN VIEN VA TIEN LUONG ===\n";
  cty.xuat();

  cty.xuatLuongDuoiTrungBinh();

  return 0;
}
