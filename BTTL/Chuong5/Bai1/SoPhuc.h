#pragma once

#include <iostream>

class SoPhuc {
private:
  double thuc;
  double ao;

public:
  SoPhuc(double t = 0, double a = 0);

  SoPhuc operator+(const SoPhuc &other) const;
  SoPhuc operator-(const SoPhuc &other) const;
  SoPhuc operator*(const SoPhuc &other) const;
  SoPhuc operator/(const SoPhuc &other) const;
  bool operator==(const SoPhuc &other) const;
  friend std::istream &operator>>(std::istream &is, SoPhuc &sp);
  friend std::ostream &operator<<(std::ostream &os, const SoPhuc &sp);
};
