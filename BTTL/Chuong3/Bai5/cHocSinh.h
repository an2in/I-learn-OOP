#pragma once

#include <string>

class cHocSinh {
private:
  std::string ma;
  std::string hoTen;
  std::string gioiTinh;
  int namSinh;
  double diemTB;

public:
  cHocSinh();
  void nhap();
  void xuat() const;
  double getDiemTB() const;
  int getNamSinh() const;
  std::string getHoTen() const;
};
