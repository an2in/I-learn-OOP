#pragma once

#include <string>

class HocSinh {
private:
  std::string hoTen;
  double diemToan;
  double diemVan;

public:
  HocSinh();
  void nhap();
  double tinhDiemTrungBinh() const;
  std::string xepLoai() const;
  void xuat() const;
};
