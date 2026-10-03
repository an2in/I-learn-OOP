#include "DuongTron.h"
#include <iostream>
using namespace std;

const double PI = 3.141592653589793;

DuongTron::DuongTron(double x, double y, double r) : x(x), y(y), r(r) {}

void DuongTron::nhap() {
  cout << "Nhap toa do tam x: ";
  cin >> x;
  cout << "Nhap toa do tam y: ";
  cin >> y;
  cout << "Nhap ban kinh r: ";
  cin >> r;
}

double DuongTron::tinhChuVi() const { return 2 * PI * r; }

double DuongTron::tinhDienTich() const { return PI * r * r; }

void DuongTron::xuat() const {
  cout << "Tam: (" << x << ", " << y << ")\n";
  cout << "Ban kinh: " << r << "\n";
  cout << "Chu vi: " << tinhChuVi() << "\n";
  cout << "Dien tich: " << tinhDienTich() << "\n";
}
