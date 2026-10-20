#include "MaTran.h"
#include <iostream>

using namespace std;

int main() {
  MaTran m1, m2;
  int chon;
  cout << "Chon che do:\n";
  cout << "  1. Tao ngau nhien 2 ma tran\n";
  cout << "  2. Nhap tay 2 ma tran\n";
  cout << "Lua chon: ";
  cin >> chon;

  if (chon == 1) {
    int d, c;
    cout << "Nhap so dong va so cot cua ma tran: ";
    cin >> d >> c;
    m1.taoNgauNhien(d, c);
    m2.taoNgauNhien(d, c);
  } else {
    cout << "\n--- Nhap ma tran 1 ---\n";
    m1.nhap();
    cout << "\n--- Nhap ma tran 2 ---\n";
    m2.nhap();
  }

  cout << "\nMa tran 1:\n" << m1;
  cout << "\nMa tran 2:\n" << m2;

  cout << "\nTong 2 ma tran (M1 + M2):\n" << (m1 + m2);
  cout << "\nHieu 2 ma tran (M1 - M2):\n" << (m1 - m2);

  cout << "\nTich 2 ma tran (M1 * M2):\n";
  MaTran tich = m1 * m2;
  cout << tich;

  return 0;
}
