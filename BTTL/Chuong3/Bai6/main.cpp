#include "SoPhuc.h"
#include <iostream>

using namespace std;

int main() {
  SoPhuc A, B;
  A.nhap();
  B.nhap();

  A.xuat();
  B.xuat();

  cout << "A + B = ";
  A.cong(B).xuat();

  cout << "\nA - B = ";
  A.tru(B).xuat();

  cout << "\nA * B = ";
  A.nhan(B).xuat();

  cout << "\nA / B = ";
  A.chia(B).xuat();
  cout << "\n";

  // test
  SoPhuc C(3, 4);
  C.xuat();
  cout << "\nPhan thuc cua C: " << C.getThuc()
       << ", phan ao cua C: " << C.getAo() << "\n";

  C.setThuc(5);
  C.setAo(-7);
  C.xuat();
  cout << "\n";

  return 0;
}
