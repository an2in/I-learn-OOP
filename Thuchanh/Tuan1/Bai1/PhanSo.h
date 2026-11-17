#ifndef PHANSO_H
#define PHANSO_H

class PhanSo {
public:
  int tuso;
  int mauso;

  // Constructor
  PhanSo(int tu = 0, int mau = 1);

  // Cac phuong thuc nhap/xuat
  void nhapPhanso();
  void inPhanSo() const;

  // Phuong thuc xu ly
  void RutGon();
  PhanSo CongPhanso(const PhanSo &other) const;
  PhanSo TruPhanSo(const PhanSo &other) const;
};

#endif // PHANSO_H
