#pragma once
#include <cmath>
#include <string>
using namespace std;
class Nhanvien {
private:
  string Hoten;
  string ngaysinh;

protected:
  double luong;

public:
  virtual void nhap();
  virtual void xuat();
  virtual double Luong() = 0;
  virtual ~Nhanvien();
};
class NhanvienSanXuat : public Nhanvien {
private:
  double LuongCanBan;
  int SoSanPham;

public:
  void nhap() override;
  void xuat() override;
  double Luong() override;
};
class NhanvienVanPhong : public Nhanvien {
private:
  int SoNgayLamViec;

public:
  void nhap() override;
  void xuat() override;
  double Luong() override;
};