#include "SinhVien.h"
#include <iostream>

using namespace std;

int main() {
  SinhVienCaoDang svcd;
  SinhVienDaiHoc svdh;

  cout << "=== NHAP THONG TIN SINH VIEN CAO DANG ===\n";
  svcd.nhap();

  cout << "\n=== NHAP THONG TIN SINH VIEN DAI HOC ===\n";
  svdh.nhap();

  cout << "\n=== KET QUA XET TOT NGHIEP ===\n";
  cout << "1. Sinh vien Cao dang:\n";
  svcd.xuat();

  cout << "\n2. Sinh vien Dai hoc:\n";
  svdh.xuat();

  return 0;
}
