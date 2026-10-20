#include "PhanSo.h"
#include <cmath>
#include <iostream>
#include <numeric>

using namespace std;

void PhanSo::rutGon() {
  if (mauso < 0) {
    tuso = -tuso;
    mauso = -mauso;
  }
  if (tuso == 0) {
    mauso = 1;
    return;
  }
  int g = std::gcd(abs(tuso), abs(mauso));
  tuso /= g;
  mauso /= g;
}

PhanSo::PhanSo(int t, int m) : tuso(t), mauso(m == 0 ? 1 : m) { rutGon(); }

PhanSo::PhanSo(const PhanSo &p) : tuso(p.tuso), mauso(p.mauso) {}

int PhanSo::LayTu() { return tuso; }

int PhanSo::LayMau() { return mauso; }

void PhanSo::GanTu(int t) {
  tuso = t;
  rutGon();
}

void PhanSo::GanMau(int m) {
  mauso = (m == 0) ? 1 : m;
  rutGon();
}

void PhanSo::Nhap() {
  cout << "  Nhap tu so: ";
  cin >> tuso;
  do {
    cout << "  Nhap mau so (khac 0): ";
    cin >> mauso;
    if (mauso == 0)
      cout << "Mau so phai khac 0, vui long nhap lai!\n";
  } while (mauso == 0);
  rutGon();
}

void PhanSo::Xuat() {
  if (mauso == 1) {
    cout << tuso;
  } else {
    cout << tuso << "/" << mauso;
  }
}

bool PhanSo::operator>(PhanSo p) {
  return (long long)tuso * p.mauso > (long long)p.tuso * mauso;
}

PhanSo PhanSo::operator+(PhanSo p) {
  int t = tuso * p.mauso + p.tuso * mauso;
  int m = mauso * p.mauso;
  return PhanSo(t, m);
}

PhanSo PhanSo::operator-(PhanSo p) {
  int t = tuso * p.mauso - p.tuso * mauso;
  int m = mauso * p.mauso;
  return PhanSo(t, m);
}
