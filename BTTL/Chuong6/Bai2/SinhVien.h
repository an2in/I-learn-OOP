#pragma once

#include <string>

class SinhVien {
protected:
  std::string mssv;
  std::string hoTen;
  std::string diaChi;
  int tongTinChi;
  double diemTB;

public:
  SinhVien(std::string ma = "", std::string ten = "", std::string dc = "",
           int tinChi = 0, double dtb = 0.0);
  void nhap();
  void xuat() const;
};

class SinhVienCaoDang : public SinhVien {
private:
  double diemThiTotNghiep;

public:
  SinhVienCaoDang(std::string ma = "", std::string ten = "", std::string dc = "",
                  int tinChi = 0, double dtb = 0.0, double diemTN = 0.0);
  void nhap();
  void xuat() const;
  bool duDieuKienTotNghiep() const;
};

class SinhVienDaiHoc : public SinhVien {
private:
  std::string tenLuanVan;
  double diemLuanVan;

public:
  SinhVienDaiHoc(std::string ma = "", std::string ten = "", std::string dc = "",
                 int tinChi = 0, double dtb = 0.0, std::string luanVan = "",
                 double diemLV = 0.0);
  void nhap();
  void xuat() const;
  bool duDieuKienTotNghiep() const;
};
