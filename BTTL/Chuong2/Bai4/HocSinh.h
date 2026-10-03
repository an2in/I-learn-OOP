#pragma once

#include <string>

class HocSinh {
private:
  std::string maHS;
  std::string hoTen;
  std::string gioiTinh;
  double diemToan;
  double diemLy;
  double diemHoa;

public:
  void nhap();
  void xuat() const;
  double tinhDiemTrungBinh() const;
};
