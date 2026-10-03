#include "MaTran.h"
#include <iostream>

using namespace std;

MaTran::MaTran(int d, int c) : soDong(d), soCot(c) {
  if (d > 0 && c > 0) {
    a.resize(d, vector<double>(c, 0.0));
  }
}

void MaTran::nhap() {
  cout << "Nhap so dong: ";
  cin >> soDong;
  cout << "Nhap so cot: ";
  cin >> soCot;

  a.assign(soDong, vector<double>(soCot, 0.0));
  cout << "Nhap cac phan tu cua ma tran:\n";
  for (int i = 0; i < soDong; ++i) {
    for (int j = 0; j < soCot; ++j) {
      cout << "a[" << i << "][" << j << "] = ";
      cin >> a[i][j];
    }
  }
}

void MaTran::xuat() const {
  for (int i = 0; i < soDong; ++i) {
    for (int j = 0; j < soCot; ++j) {
      cout << a[i][j] << "\t";
    }
    cout << "\n";
  }
}

MaTran MaTran::cong(const MaTran &other) const {
  if (soDong != other.soDong || soCot != other.soCot) {
    cout << "Yo, wrong wrong bro!\n";
    return MaTran();
  }
  MaTran kq(soDong, soCot);
  for (int i = 0; i < soDong; ++i) {
    for (int j = 0; j < soCot; ++j) {
      kq.a[i][j] = this->a[i][j] + other.a[i][j];
    }
  }
  return kq;
}

MaTran MaTran::tru(const MaTran &other) const {
  if (soDong != other.soDong || soCot != other.soCot) {
    cout << "Yo, wrong wrong bro!\n";
    return MaTran();
  }
  MaTran kq(soDong, soCot);
  for (int i = 0; i < soDong; ++i) {
    for (int j = 0; j < soCot; ++j) {
      kq.a[i][j] = this->a[i][j] - other.a[i][j];
    }
  }
  return kq;
}

MaTran MaTran::nhan(const MaTran &other) const {
  if (soCot != other.soDong) {
    cout << "Yo, wrong wrong bro!\n";
    return MaTran();
  }
  MaTran kq(soDong, other.soCot);
  for (int i = 0; i < soDong; ++i) {
    for (int j = 0; j < other.soCot; ++j) {
      kq.a[i][j] = 0;
      for (int k = 0; k < soCot; ++k) {
        kq.a[i][j] += this->a[i][k] * other.a[k][j];
      }
    }
  }
  return kq;
}
