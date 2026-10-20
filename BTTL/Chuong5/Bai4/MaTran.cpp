#include "MaTran.h"
#include <iomanip>
#include <limits>
#include <random>

using namespace std;

MaTran::MaTran(int dong, int cot) : m(dong), n(cot) {
  if (m > 0 && n > 0) {
    a.assign(m, vector<int>(n, 0));
  } else {
    m = n = 0;
  }
}

void MaTran::taoNgauNhien(int dong, int cot) {
  m = (dong > 0) ? dong : 0;
  n = (cot > 0) ? cot : 0;
  a.assign(m, vector<int>(n, 0));

  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<int> dis(numeric_limits<int>::min(),
                                    numeric_limits<int>::max());

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      a[i][j] = dis(gen);
    }
  }
}

void MaTran::nhap() {
  cout << "Nhap so dong: ";
  cin >> m;
  cout << "Nhap so cot: ";
  cin >> n;
  if (m <= 0 || n <= 0) {
    m = n = 0;
    a.clear();
    return;
  }

  a.assign(m, vector<int>(n, 0));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << "  a[" << i << "][" << j << "]: ";
      cin >> a[i][j];
    }
  }
}

void MaTran::xuat() const {
  if (m == 0 || n == 0) {
    cout << "Ma tran rong!\n";
    return;
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << setw(12) << a[i][j];
    }
    cout << "\n";
  }
}

MaTran MaTran::operator+(const MaTran &other) const {
  if (m != other.m || n != other.n) {
    cerr << "Loi: Hai ma tran khong cung kich thuoc de cong!\n";
    return MaTran();
  }
  MaTran kq(m, n);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      kq.a[i][j] = a[i][j] + other.a[i][j];
    }
  }
  return kq;
}

MaTran MaTran::operator-(const MaTran &other) const {
  if (m != other.m || n != other.n) {
    cerr << "Loi: Hai ma tran khong cung kich thuoc de tru!\n";
    return MaTran();
  }
  MaTran kq(m, n);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      kq.a[i][j] = a[i][j] - other.a[i][j];
    }
  }
  return kq;
}

MaTran MaTran::operator*(const MaTran &other) const {
  if (n != other.m) {
    cerr << "Loi: So cot ma tran 1 phai bang so dong ma tran 2 de nhan!\n";
    return MaTran();
  }
  MaTran kq(m, other.n);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < other.n; ++j) {
      for (int k = 0; k < n; ++k) {
        kq.a[i][j] += a[i][k] * other.a[k][j];
      }
    }
  }
  return kq;
}

std::istream &operator>>(std::istream &is, MaTran &mt) {
  mt.nhap();
  return is;
}

std::ostream &operator<<(std::ostream &os, const MaTran &mt) {
  mt.xuat();
  return os;
}
