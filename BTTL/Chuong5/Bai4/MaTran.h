#pragma once

#include <iostream>
#include <vector>

class MaTran {
private:
  int m, n;
  std::vector<std::vector<int>> a;

public:
  MaTran(int dong = 0, int cot = 0);

  void taoNgauNhien(int dong, int cot);
  void nhap();
  void xuat() const;

  MaTran operator+(const MaTran &other) const;
  MaTran operator-(const MaTran &other) const;
  MaTran operator*(const MaTran &other) const;

  friend std::istream &operator>>(std::istream &is, MaTran &mt);
  friend std::ostream &operator<<(std::ostream &os, const MaTran &mt);
};
