#pragma once

#include <vector>

class cArray {
private:
  std::vector<int> a;

public:
  void nhap();
  void xuat() const;
  void taoNgauNhien(int n);
  int demXuatHien(int x) const;
  bool kiemTraTangDan() const;
  int timLeNhoNhat() const;
  void sapXepTangDan();
};
