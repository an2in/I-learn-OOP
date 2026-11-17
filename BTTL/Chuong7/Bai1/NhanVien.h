#pragma once

#include <string>
#include <vector>

class NhanVien {
protected:
  std::string hoTen;
  std::string ngaySinh;
  double luongCoBan;

public:
  NhanVien(std::string ten = "", std::string ns = "", double lcb = 0.0);
  virtual ~NhanVien() = default;

  virtual void nhap();
  virtual void xuat() const;
  virtual double tinhLuong() const = 0;

  std::string getHoTen() const;
};

class NhanVienVanPhong : public NhanVien {
private:
  int soNgayLamViec;
  double troCap;

public:
  NhanVienVanPhong(std::string ten = "", std::string ns = "", double lcb = 0.0,
                   int soNgay = 0, double tc = 0.0);
  void nhap() override;
  void xuat() const override;
  double tinhLuong() const override;
};

class NhanVienSanXuat : public NhanVien {
private:
  int soSanPham;

public:
  NhanVienSanXuat(std::string ten = "", std::string ns = "", double lcb = 0.0,
                  int soSP = 0);
  void nhap() override;
  void xuat() const override;
  double tinhLuong() const override;
};

class NhanVienQuanLy : public NhanVien {
private:
  double heSoChucVu;
  double thuong;

public:
  NhanVienQuanLy(std::string ten = "", std::string ns = "", double lcb = 0.0,
                 double heSo = 1.0, double th = 0.0);
  void nhap() override;
  void xuat() const override;
  double tinhLuong() const override;
};

class CongTyABC {
private:
  std::vector<NhanVien *> ds;

public:
  ~CongTyABC();
  void nhap();
  void xuat() const;
  double tinhTongLuong() const;
  void timKiemTheoTen(const std::string &ten) const;
};
