#pragma once

#include "PhanSo.h"
#include <vector>

class DSPhanSo {
private:
  std::vector<PhanSo> a;

public:
  void Nhap();
  void Xuat();
  PhanSo TimMax();
  PhanSo TinhTong();
};
