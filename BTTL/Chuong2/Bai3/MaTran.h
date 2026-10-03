#pragma once

#include <vector>

class MaTran {
private:
  int soDong;
  int soCot;
  std::vector<std::vector<double>> a;

public:
  MaTran(int d = 0, int c = 0);

  void nhap();
  void xuat() const;

  MaTran cong(const MaTran &other) const;
  MaTran tru(const MaTran &other) const;
  MaTran nhan(const MaTran &other) const;
};
