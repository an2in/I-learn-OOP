#pragma once

#include <vector>

class PhanSo {
private:
  int tu, mau;

public:
  PhanSo(int tu = 0, int mau = 1);
  void nhap();
  void xuat() const;
  void rutGon();
  PhanSo cong(const PhanSo &other) const;
  bool lonHon(const PhanSo &other) const;
};

class DayPhanSo {
private:
  std::vector<PhanSo> ds;

public:
  void nhap();
  void xuat() const;
  PhanSo tinhTong() const;
  PhanSo timMax() const;
};
