#include "DaThuc.h"
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

DaThuc::DaThuc(int n) {
  bac = (n >= 0) ? n : 0;
  heSo.assign(bac + 1, 0.0);
}

void DaThuc::nhap() {
  cout << "Nhap bac cua da thuc: ";
  cin >> bac;
  if (bac < 0)
    bac = 0;
  heSo.assign(bac + 1, 0.0);
  for (int i = bac; i >= 0; --i) {
    cout << "  He so x^" << i << ": ";
    cin >> heSo[i];
  }
}

void DaThuc::xuat() const {
  bool first = true;
  bool allZero = true;

  for (int i = bac; i >= 0; --i) {
    if (heSo[i] == 0)
      continue;

    allZero = false;
    if (!first) {
      if (heSo[i] > 0)
        cout << " + ";
      else
        cout << " - ";
    } else {
      if (heSo[i] < 0)
        cout << "-";
      first = false;
    }

    double absHeSo = abs(heSo[i]);
    if (i == 0) {
      cout << absHeSo;
    } else if (i == 1) {
      if (absHeSo == 1)
        cout << "x";
      else
        cout << absHeSo << "x";
    } else {
      if (absHeSo == 1)
        cout << "x^" << i;
      else
        cout << absHeSo << "x^" << i;
    }
  }

  if (allZero) {
    cout << 0;
  }
}

double DaThuc::tinhGiaTri(double x) const {
  double val = 0.0;
  for (int i = 0; i <= bac; ++i) {
    val += heSo[i] * pow(x, i);
  }
  return val;
}

DaThuc DaThuc::cong(const DaThuc &other) const {
  int maxBac = max(this->bac, other.bac);
  DaThuc kq(maxBac);
  for (int i = 0; i <= maxBac; ++i) {
    double h1 = (i <= this->bac) ? this->heSo[i] : 0.0;
    double h2 = (i <= other.bac) ? other.heSo[i] : 0.0;
    kq.heSo[i] = h1 + h2;
  }
  while (kq.bac > 0 && kq.heSo[kq.bac] == 0) {
    kq.bac--;
  }
  return kq;
}

DaThuc DaThuc::tru(const DaThuc &other) const {
  int maxBac = max(this->bac, other.bac);
  DaThuc kq(maxBac);
  for (int i = 0; i <= maxBac; ++i) {
    double h1 = (i <= this->bac) ? this->heSo[i] : 0.0;
    double h2 = (i <= other.bac) ? other.heSo[i] : 0.0;
    kq.heSo[i] = h1 - h2;
  }
  while (kq.bac > 0 && kq.heSo[kq.bac] == 0) {
    kq.bac--;
  }
  return kq;
}
