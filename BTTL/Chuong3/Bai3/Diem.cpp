#include "Diem.h"
#include <cmath>
#include <iostream>

using namespace std;

Diem::Diem(double x, double y) : x(x), y(y) {}

void Diem::nhap() {
  cout << "Nhap x: ";
  cin >> x;
  cout << "Nhap y: ";
  cin >> y;
}

void Diem::xuat() const { cout << "(" << x << ", " << y << ")"; }

double Diem::tinhKhoangCach(const Diem &other) const {
  return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
}
