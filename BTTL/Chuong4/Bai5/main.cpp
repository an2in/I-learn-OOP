#include "cBook.h"
#include <iostream>

using namespace std;

int main() {
  cListBook thuVien;

  cout << "=== NHAP DANH SACH SACH ===\n";
  thuVien.nhap();

  cout << "\n=== DANH SACH SACH TRONG THU VIEN ===\n";
  thuVien.xuat();

  cout << "\n=== CUON SACH DUOC XUAT BAN GAN DAY NHAT ===\n";
  cBook sachMoiNhat = thuVien.timXuatBanGanNhat();
  sachMoiNhat.xuat();

  return 0;
}
