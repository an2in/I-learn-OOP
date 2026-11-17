#include "SoPhuc.h"
#include <iostream>

using namespace std;

void SoPhuc::NhapSoAo() {
  cout << "thuc:";
  cin >> x;
  cout << "ao:";
  cin >> y;
}

void SoPhuc::inSoAo() const { cout << "thuc: " << x << " | ao: " << y; }

void SoPhuc::DinhGTSoAo(double real, double fake) {
  x = real;
  y = fake;
}
