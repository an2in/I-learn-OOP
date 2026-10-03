#pragma once

class Diem {
private:
  double x, y;

public:
  Diem(double x = 0, double y = 0);
  void nhap();
  void xuat() const;
  double tinhKhoangCach(const Diem &other) const;
};
