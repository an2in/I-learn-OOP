#include "MaTran.h"
#include <iostream>

using namespace std;

int main() {
  MaTran A, B;
  A.nhap();
  B.nhap();
  cout << "Ma tran A:\n";
  A.xuat();
  cout << "\nMa tran B:\n";
  B.xuat();
  cout << "Tong 2 ma tran (A + B):\n";
  A.cong(B).xuat();
  cout << "\nHieu 2 ma tran (A - B):\n";
  A.tru(B).xuat();
  cout << "\nTich 2 ma tran (A * B):\n";
  A.nhan(B).xuat();

  return 0;
}
