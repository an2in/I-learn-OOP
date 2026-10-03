#include "cArray.h"
#include <iostream>

using namespace std;

int main() {
  int n;
  cout << "Nhap so luong phan tu n: ";
  cin >> n;
  cArray arr(n);
  cout << "Mang ngau nhien duoc tao:\n";
  arr.xuat();
  int maxAm = arr.timAmLonNhat();
  if (maxAm < 0) {
    cout << "So am lon nhat trong mang: " << maxAm << "\n";
  }
  int x;
  cout << "Nhap so nguyen x can dem: ";
  cin >> x;
  cout << "So lan xuat hien cua " << x << ": " << arr.demXuatHien(x) << "\n";
  if (arr.kiemTraGiamDan()) {
    cout << "Mang dang giam dan.\n";
  } else {
    cout << "Mang khong giam dan.\n";
  }
  cout << "Mang sau khi sap xep tang dan:\n";
  arr.sapXepTangDan();
  arr.xuat();

  return 0;
}
