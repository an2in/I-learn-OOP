#include "PhanSo.h"
#include <iostream>
#include <numeric>

PhanSo::PhanSo(int tu, int mau) : tu(tu), mau(mau) {}

void PhanSo::nhap() {
  std::cout << "Nhap tu so: ";
  std::cin >> tu;
  do {
    std::cout << "Nhap mau so: ";
    std::cin >> mau;
  } while (mau == 0);
  rutGon();
}

void PhanSo::xuat() const {
  if (mau == 1) {
    std::cout << tu;
  } else if (tu == 0) {
    std::cout << 0;
  } else {
    std::cout << tu << "/" << mau;
  }
}

void PhanSo::rutGon() {
  if (mau < 0) {
    tu = -tu;
    mau = -mau;
  }
  int d = std::gcd(tu, mau);
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

PhanSo PhanSo::tru(const PhanSo &other) const {
  PhanSo kq;
  kq.tu = this->tu * other.mau - this->mau * other.tu;
  kq.mau = this->mau * other.mau;
  kq.rutGon();
  return kq;
}

PhanSo PhanSo::nhan(const PhanSo &other) const {
  PhanSo kq;
  kq.tu = this->tu * other.tu;
  kq.mau = this->mau * other.mau;
  kq.rutGon();
  return kq;
}

PhanSo PhanSo::chia(const PhanSo &other) const {
  PhanSo kq;
  kq.tu = this->tu * other.mau;
  kq.mau = this->mau * other.tu;
  kq.rutGon();
  return kq;
}
