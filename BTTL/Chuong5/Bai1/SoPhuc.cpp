#include "SoPhuc.h"

SoPhuc::SoPhuc(double t, double a) : thuc(t), ao(a) {}

SoPhuc SoPhuc::operator+(const SoPhuc &other) const {
  return SoPhuc(thuc + other.thuc, ao + other.ao);
}

SoPhuc SoPhuc::operator-(const SoPhuc &other) const {
  return SoPhuc(thuc - other.thuc, ao - other.ao);
}

SoPhuc SoPhuc::operator*(const SoPhuc &other) const {
  return SoPhuc(thuc * other.thuc - ao * other.ao,
                thuc * other.ao + ao * other.thuc);
}

SoPhuc SoPhuc::operator/(const SoPhuc &other) const {
  double mau = other.thuc * other.thuc + other.ao * other.ao;
  if (mau == 0) {
    std::cerr << "Loi: Mau so bang 0!\n";
    return SoPhuc();
  }
  return SoPhuc((thuc * other.thuc + ao * other.ao) / mau,
                (ao * other.thuc - thuc * other.ao) / mau);
}

bool SoPhuc::operator==(const SoPhuc &other) const {
  return (thuc == other.thuc) && (ao == other.ao);
}

std::istream &operator>>(std::istream &is, SoPhuc &sp) {
  std::cout << "  Phan thuc: ";
  is >> sp.thuc;
  std::cout << "  Phan ao: ";
  is >> sp.ao;
  return is;
}

std::ostream &operator<<(std::ostream &os, const SoPhuc &sp) {
  if (sp.ao == 0) {
    os << sp.thuc;
  } else if (sp.thuc == 0) {
    os << sp.ao << "i";
  } else if (sp.ao < 0) {
    os << sp.thuc << " - " << -sp.ao << "i";
  } else {
    os << sp.thuc << " + " << sp.ao << "i";
  }
  return os;
}
