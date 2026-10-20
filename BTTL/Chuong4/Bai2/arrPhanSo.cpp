#include "arrPhanSo.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <random>

using namespace std;

// ================= PhanSo =================
void PhanSo::rutGon() {
  if (mau < 0) {
    tu = -tu;
    mau = -mau;
  }
  int d = gcd(tu, mau);
  if (d != 0) {
    tu /= d;
    mau /= d;
  }
}

void PhanSo::nhap() {
  cout << "  Nhap tu: ";
  cin >> tu;
  do {
    cout << "  Nhap mau (khac 0): ";
    cin >> mau;
  } while (mau == 0);
  rutGon();
}

void PhanSo::xuat() const {
  if (mau == 1) {
    cout << tu;
  } else if (tu == 0) {
    cout << 0;
  } else {
    cout << tu << "/" << mau;
  }
}

bool PhanSo::lonHon(const PhanSo &other) const {
  return (long long)tu * other.mau > (long long)other.tu * mau;
}

bool PhanSo::tuLaNguyenTo() const {
  if (tu < 2)
    return false;
  for (int i = 2; i * i <= tu; ++i) {
    if (tu % i == 0)
      return false;
  }
  return true;
}

// ================= arrPhanSo =================
void arrPhanSo::nhap() {
  int n;
  cout << "Nhap so luong phan so: ";
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; ++i) {
    cout << "Phan so " << i + 1 << ":\n";
    a[i].nhap();
  }
}

void arrPhanSo::xuat() const {
  for (size_t i = 0; i < a.size(); ++i) {
    a[i].xuat();
    if (i + 1 < a.size())
      cout << "  ";
  }
  cout << "\n";
}

void arrPhanSo::taoNgauNhien(int n) {
  if (n <= 0)
    return;
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<int> disTu(-20, 20);
  uniform_int_distribution<int> disMau(1, 20);
  a.resize(n);
  for (int i = 0; i < n; ++i) {
    a[i].tu = disTu(gen);
    a[i].mau = disMau(gen);
    a[i].rutGon();
  }
}

PhanSo arrPhanSo::timMax() const {
  if (a.empty())
    return {0, 1};
  PhanSo psMax = a[0];
  for (size_t i = 1; i < a.size(); ++i) {
    if (a[i].lonHon(psMax)) {
      psMax = a[i];
    }
  }
  return psMax;
}

int arrPhanSo::demTuNguyenTo() const {
  int dem = 0;
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i].tuLaNguyenTo())
      dem++;
  }
  return dem;
}

void arrPhanSo::sapXepTangDan() {
  sort(a.begin(), a.end(), [](const PhanSo &x, const PhanSo &y) {
    return (long long)x.tu * y.mau < (long long)y.tu * x.mau;
  });
}
