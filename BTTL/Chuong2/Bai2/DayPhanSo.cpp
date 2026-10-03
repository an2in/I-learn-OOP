#include "DayPhanSo.h"
#include <iostream>
#include <numeric>

using namespace std;

PhanSo::PhanSo(int tu, int mau) : tu(tu), mau(mau) {}

void PhanSo::nhap() {
  cout << "  Tu so: ";
  cin >> tu;
  do {
    cout << "  Mau so: ";
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

PhanSo PhanSo::cong(const PhanSo &other) const {
  PhanSo kq;
  kq.tu = this->tu * other.mau + this->mau * other.tu;
  kq.mau = this->mau * other.mau;
  kq.rutGon();
  return kq;
}

bool PhanSo::lonHon(const PhanSo &other) const {
  return (long long)this->tu * other.mau > (long long)other.tu * this->mau;
}

void DayPhanSo::nhap() {
  int n;
  cout << "Nhap so luong phan so: ";
  cin >> n;
  ds.resize(n);
  for (int i = 0; i < n; ++i) {
    cout << "Phan so " << i + 1 << ":\n";
    ds[i].nhap();
  }
}

void DayPhanSo::xuat() const {
  for (size_t i = 0; i < ds.size(); ++i) {
    ds[i].xuat();
    if (i + 1 < ds.size())
      cout << "  ";
  }
  cout << "\n";
}

PhanSo DayPhanSo::tinhTong() const {
  PhanSo tong(0, 1);
  for (const auto &ps : ds) {
    tong = tong.cong(ps);
  }
  return tong;
}

PhanSo DayPhanSo::timMax() const {
  PhanSo psMax = ds[0];
  for (size_t i = 1; i < ds.size(); ++i) {
    if (ds[i].lonHon(psMax)) {
      psMax = ds[i];
    }
  }
  return psMax;
}
