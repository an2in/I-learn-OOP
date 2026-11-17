#pragma once

#include <string>
#include <vector>

class CBVC {
protected:
  std::string maCB;
  std::string hoTen;
  std::string gioiTinh;

public:
  CBVC(std::string ma = "", std::string ten = "", std::string phai = "");
  void nhap();
  void xuat() const;
};

class GiangVien : public CBVC {
private:
  int soGioDay;
  int soGioNC;

public:
  GiangVien(std::string ma = "", std::string ten = "", std::string phai = "",
            int day = 0, int nc = 0);
  void nhap();
  void xuat() const;
  double tinhLuong(double donGia = 100000) const;
};

class NhanVienHanhChinh : public CBVC {
private:
  int soNgayLamViec;
  int soGioLamThem;

public:
  NhanVienHanhChinh(std::string ma = "", std::string ten = "",
                    std::string phai = "", int ngay = 0, int them = 0);
  void nhap();
  void xuat() const;
  double tinhLuong(double tienCongNgay = 200000, double donGiaThem = 50000) const;
};

class QuanLyCBVC {
private:
  std::vector<GiangVien> dsGV;
  std::vector<NhanVienHanhChinh> dsNVHC;

public:
  void nhap();
  void xuat() const;
  double tinhTongLuong() const;
};
