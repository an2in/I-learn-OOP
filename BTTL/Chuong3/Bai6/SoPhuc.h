#pragma once

class SoPhuc {
private:
  double thuc, ao;

public:
  SoPhuc(double thuc = 0, double ao = 0);

  void setThuc(double thuc);
  void setAo(double ao);
  double getThuc() const;
  double getAo() const;
  void nhap();
  void xuat() const;
  SoPhuc cong(const SoPhuc &other) const;
  SoPhuc tru(const SoPhuc &other) const;
  SoPhuc nhan(const SoPhuc &other) const;
  SoPhuc chia(const SoPhuc &other) const;
};
