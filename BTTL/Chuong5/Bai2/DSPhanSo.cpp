#include "DSPhanSo.h"
#include <iostream>

using namespace std;

void DSPhanSo::Nhap() {
  int n;
  cout << "Nhap so luong phan so: ";
  cin >> n;
  if (n <= 0)
    return;

  a.resize(n);
  for (int i = 0; i < n; ++i) {
    cout << "Nhap phan so thu " << i + 1 << ":\n";
    a[i].Nhap();
  }
}

void DSPhanSo::Xuat() {
  for (int i = 0; i < (int)a.size(); ++i) {
    a[i].Xuat();
    cout << " ";
  }
  cout << endl;
}

PhanSo DSPhanSo::TimMax() {
  if (a.empty())
    return PhanSo();

  PhanSo maxPS = a[0];
  for (int i = 1; i < (int)a.size(); ++i) {
    if (a[i] > maxPS) {
      maxPS = a[i];
    }
  }
  return maxPS;
}

PhanSo DSPhanSo::TinhTong() {
  PhanSo tong(0, 1);
  for (int i = 0; i < (int)a.size(); ++i) {
    tong = tong + a[i];
  }
  return tong;
}
