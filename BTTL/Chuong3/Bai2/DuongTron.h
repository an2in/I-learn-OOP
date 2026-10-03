#pragma once

class DuongTron {
private:
  double x, y, r;

public:
  DuongTron(double x = 0, double y = 0, double r = 0);
  void nhap();
  double tinhChuVi() const;
  double tinhDienTich() const;
  void xuat() const;
};
