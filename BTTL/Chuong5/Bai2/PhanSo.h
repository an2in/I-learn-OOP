#pragma once

class PhanSo {
private:
  int tuso;
  int mauso;
  void rutGon();

public:
  PhanSo(int t = 0, int m = 1);
  PhanSo(const PhanSo &p);
  int LayTu();
  int LayMau();
  void GanTu(int t);
  void GanMau(int m);
  void Nhap();
  void Xuat();
  bool operator>(PhanSo);
  PhanSo operator+(PhanSo);
  PhanSo operator-(PhanSo);
};
