#pragma once

#include <vector>

class DaThuc {
private:
  int bac;
  std::vector<double> heSo; // heSo[i] la he so cua x^i

public:
  DaThuc(int n = 0);
  void nhap();
  void xuat() const;
  double tinhGiaTri(double x) const;
  DaThuc cong(const DaThuc &other) const;
  DaThuc tru(const DaThuc &other) const;
};
