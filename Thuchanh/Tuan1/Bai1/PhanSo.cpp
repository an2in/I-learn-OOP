#include "PhanSo.h"
#include <iostream>
#include <numeric>

using namespace std;

// Constructor
PhanSo::PhanSo(int tu, int mau) : tuso(tu), mauso(mau) {}

// Nhap phan so tu ban phim
void PhanSo::nhapPhanso() {
  cout << "Tu so: ";
  cin >> tuso;
  cout << "Mau so: ";
  cin >> mauso;
}

// In phan so ra man hinh
void PhanSo::inPhanSo() const {
  cout << tuso << "/" << mauso << "\n";
}

// Rut gon phan so
void PhanSo::RutGon() {
  if (mauso == 0) return;
  int a = std::gcd(tuso, mauso);
  tuso /= a;
  mauso /= a;
}

// Cong hai phan so: a/b + c/d = (ad + bc) / bd
PhanSo PhanSo::CongPhanso(const PhanSo &other) const {
  PhanSo tong;
  tong.tuso = tuso * other.mauso + mauso * other.tuso;
  tong.mauso = mauso * other.mauso;
  tong.RutGon();
  return tong;
}

// Tru hai phan so: a/b - c/d = (ad - bc) / bd
PhanSo PhanSo::TruPhanSo(const PhanSo &other) const {
  PhanSo hieu;
  hieu.tuso = tuso * other.mauso - mauso * other.tuso;
  hieu.mauso = mauso * other.mauso;
  hieu.RutGon();
  return hieu;
}
