#include "cArray.h"
#include <iostream>

using namespace std;

int main() {
  cArray arr;
  arr.nhap();

  cout << "Day so vua nhap: ";
  arr.xuat();

  if (arr.kiemTraTangDan()) {
    cout << "Day so tang dan.\n";
  } else {
    cout << "Day so khong tang dan.\n";
  }

  int minLe = arr.timLeNhoNhat();
  cout << "Phan tu le nho nhat: " << minLe << "\n";

  int x;
  cout << "Nhap x can dem: ";
  cin >> x;
  cout << "So lan xuat hien cua " << x << ": " << arr.demXuatHien(x) << "\n";

  cout << "Day so sau khi sap xep tang dan: ";
  arr.sapXepTangDan();
  arr.xuat();

  return 0;
}
