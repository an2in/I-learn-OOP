#pragma once

class DonThuc {
private:
  double heSo;
  int soMu;

public:
  DonThuc(double a = 0, int b = 0);
  void nhap();
  void xuat() const;
  void setDonThuc(double a, int b);
  double tinhGiaTri(double x) const;
  DonThuc tinhDaoHam() const;
  DonThuc cong(const DonThuc &other) const;
};
