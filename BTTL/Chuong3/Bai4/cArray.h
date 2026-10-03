#pragma once

#include <vector>

class cArray {
private:
  std::vector<int> a;

public:
  cArray(int n = 0);
  void xuat() const;
  int timAmLonNhat() const;
  int demXuatHien(int x) const;
  bool kiemTraGiamDan() const;
  void sapXepTangDan();
};
