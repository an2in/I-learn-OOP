#pragma once

class SoPhuc {
private:
  double x, y;

public:
  void NhapSoAo();
  void inSoAo() const;
  void DinhGTSoAo(double real, double fake);
  SoPhuc Cong(SoPhuc other) const;
  SoPhuc Tru(SoPhuc other) const;
  SoPhuc Nhan(SoPhuc other) const;
  SoPhuc Chia(SoPhuc other) const;
};