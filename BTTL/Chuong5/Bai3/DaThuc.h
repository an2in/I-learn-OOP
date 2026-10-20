#pragma once

#include <iostream>
#include <vector>

class DaThuc {
private:
  int bac;
  std::vector<double> heSo; // heSo[i] la he so cua x^i

public:
  DaThuc(int n = 0);
  double tinhGiaTri(double x) const;

  DaThuc operator+(const DaThuc &other) const;
  DaThuc operator-(const DaThuc &other) const;

  friend std::istream &operator>>(std::istream &is, DaThuc &dt);
  friend std::ostream &operator<<(std::ostream &os, const DaThuc &dt);
};
