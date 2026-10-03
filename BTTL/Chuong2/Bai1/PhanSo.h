#pragma once

class PhanSo {
private:
  int tu;
  int mau;

public:
  PhanSo(int tu = 0, int mau = 1);
  void nhap();
  void xuat() const;
  void rutGon();
  PhanSo cong(const PhanSo &other) const;
  PhanSo tru(const PhanSo &other) const;
  PhanSo nhan(const PhanSo &other) const;
  PhanSo chia(const PhanSo &other) const;
};
