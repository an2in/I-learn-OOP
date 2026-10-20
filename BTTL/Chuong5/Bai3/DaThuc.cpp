#include "DaThuc.h"
#include <algorithm>
#include <cmath>

using namespace std;

DaThuc::DaThuc(int n) {
  bac = (n >= 0) ? n : 0;
  heSo.assign(bac + 1, 0.0);
}

double DaThuc::tinhGiaTri(double x) const {
  double val = 0.0;
  for (int i = 0; i <= bac; ++i) {
    val += heSo[i] * pow(x, i);
  }
  return val;
}

DaThuc DaThuc::operator+(const DaThuc &other) const {
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
  kq.heSo.resize(kq.bac + 1);
  return kq;
}

DaThuc DaThuc::operator-(const DaThuc &other) const {
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
  kq.heSo.resize(kq.bac + 1);
  return kq;
}

std::istream &operator>>(std::istream &is, DaThuc &dt) {
  cout << "Nhap bac cua da thuc: ";
  is >> dt.bac;
  if (dt.bac < 0)
    dt.bac = 0;
  dt.heSo.assign(dt.bac + 1, 0.0);
  for (int i = dt.bac; i >= 0; --i) {
    cout << "  He so x^" << i << ": ";
    is >> dt.heSo[i];
  }
  return is;
}

std::ostream &operator<<(std::ostream &os, const DaThuc &dt) {
  bool first = true;
  bool allZero = true;

  for (int i = dt.bac; i >= 0; --i) {
    if (dt.heSo[i] == 0)
      continue;

    allZero = false;
    if (!first) {
      if (dt.heSo[i] > 0)
        os << " + ";
      else
        os << " - ";
    } else {
      if (dt.heSo[i] < 0)
        os << "-";
      first = false;
    }

    double absHeSo = abs(dt.heSo[i]);
    if (i == 0) {
      os << absHeSo;
    } else if (i == 1) {
      if (absHeSo == 1)
        os << "x";
      else
        os << absHeSo << "x";
    } else {
      if (absHeSo == 1)
        os << "x^" << i;
      else
        os << absHeSo << "x^" << i;
    }
  }

  if (allZero) {
    os << 0;
  }
  return os;
}
