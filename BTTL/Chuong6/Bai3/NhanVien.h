#pragma once

#include <string>
#include <vector>

class NhanVien {
protected:
  std::string maNV;
  std::string hoTen;
  int tuoi;
  std::string sdt;
  std::string email;
  double luongCoBan;

public:
  NhanVien(std::string ma = "", std::string ten = "", int t = 0,
           std::string tel = "", std::string mail = "", double lcb = 0.0);
  void nhap();
  void xuat() const;
  double getLuongCoBan() const;
};

class LapTrinhVien : public NhanVien {
private:
  int soGioOvertime;

public:
  LapTrinhVien(std::string ma = "", std::string ten = "", int t = 0,
               std::string tel = "", std::string mail = "", double lcb = 0.0,
               int ot = 0);
  void nhap();
  void xuat() const;
  double tinhLuong() const;
};

class KiemChungVien : public NhanVien {
private:
  int soLoi;

public:
  KiemChungVien(std::string ma = "", std::string ten = "", int t = 0,
                std::string tel = "", std::string mail = "", double lcb = 0.0,
                int loi = 0);
  void nhap();
  void xuat() const;
  double tinhLuong() const;
};

class CongTy {
private:
  std::vector<LapTrinhVien> dsLTV;
  std::vector<KiemChungVien> dsKCV;

public:
  void nhap();
  void xuat() const;
  double tinhLuongTrungBinh() const;
  void xuatLuongDuoiTrungBinh() const;
};
