#include "SoPhuc.h"
#include <iostream>

using namespace std;

SoPhuc::SoPhuc(double thuc, double ao) : thuc(thuc), ao(ao) {}

void SoPhuc::setThuc(double thuc) { this->thuc = thuc; }

void SoPhuc::setAo(double ao) { this->ao = ao; }

double SoPhuc::getThuc() const { return thuc; }

double SoPhuc::getAo() const { return ao; }

void SoPhuc::nhap() {
  cout << "Nhap phan thuc: ";
  cin >> thuc;
  cout << "Nhap phan ao: ";
  cin >> ao;
}

void SoPhuc::xuat() const {
  if (ao >= 0) {
    cout << thuc << " + " << ao << "i";
  } else {
    cout << thuc << " - " << -ao << "i";
  }
}

SoPhuc SoPhuc::cong(const SoPhuc &other) const {
  return SoPhuc(thuc + other.thuc, ao + other.ao);
}

SoPhuc SoPhuc::tru(const SoPhuc &other) const {
  return SoPhuc(thuc - other.thuc, ao - other.ao);
}

SoPhuc SoPhuc::nhan(const SoPhuc &other) const {
  return SoPhuc(thuc * other.thuc - ao * other.ao,
                thuc * other.ao + ao * other.thuc);
}

SoPhuc SoPhuc::chia(const SoPhuc &other) const {
  double mau = other.thuc * other.thuc + other.ao * other.ao;
  if (mau == 0) {
    cout << "The hell bro?\n";
    return SoPhuc();
  }
  double thucMoi = (thuc * other.thuc + ao * other.ao) / mau;
  double aoMoi = (other.thuc * ao - thuc * other.ao) / mau;
  return SoPhuc(thucMoi, aoMoi);
}
