#include "DonThuc.h"
#include <cmath>
#include <iostream>

using namespace std;

DonThuc::DonThuc(double a, int b) : heSo(a), soMu(b) {}

void DonThuc::nhap() {
  cout << "Nhap he so a: ";
  cin >> heSo;
  cout << "Nhap so mu b: ";
  cin >> soMu;
}

void DonThuc::setDonThuc(double a, int b) {
  heSo = a;
  soMu = b;
}

void DonThuc::xuat() const {
  if (heSo == 0) {
    cout << 0;
  } else if (soMu == 0) {
    cout << heSo;
  } else if (soMu == 1) {
    cout << heSo << "x";
  } else {
    cout << heSo << "x^" << soMu;
  }
}

double DonThuc::tinhGiaTri(double x) const { return heSo * pow(x, soMu); }

DonThuc DonThuc::tinhDaoHam() const {
  if (soMu == 0) {
    return DonThuc(0, 0);
  }
  return DonThuc(heSo * soMu, soMu - 1);
}

DonThuc DonThuc::cong(const DonThuc &other) const {
  if (this->soMu != other.soMu) {
    cout << "Hai don thuc khong cung bac, khong the cong!\n";
    return DonThuc(0, 0);
  }
  return DonThuc(this->heSo + other.heSo, this->soMu);
}
