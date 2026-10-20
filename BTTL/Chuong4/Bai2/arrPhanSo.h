#pragma once

#include <vector>

struct PhanSo {
  int tu;
  int mau;

  void nhap();
  void xuat() const;
  void rutGon();
  bool lonHon(const PhanSo &other) const;
  bool tuLaNguyenTo() const;
};

class arrPhanSo {
private:
  std::vector<PhanSo> a;

public:
  void nhap();
  void xuat() const;
  void taoNgauNhien(int n);
  PhanSo timMax() const;
  int demTuNguyenTo() const;
  void sapXepTangDan();
};
