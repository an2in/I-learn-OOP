#include "cArray.h"
#include <algorithm>
#include <iostream>
#include <limits>
#include <random>

using namespace std;

void cArray::nhap() {
  int n;
  cout << "Nhap so phan tu n: ";
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; ++i) {
    cout << "a[" << i << "] = ";
    cin >> a[i];
  }
}

void cArray::xuat() const {
  for (size_t i = 0; i < a.size(); ++i) {
    cout << a[i] << " ";
  }
  cout << "\n";
}

void cArray::taoNgauNhien(int n) {
  if (n <= 0)
    return;
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<int> dis(numeric_limits<int>::min(),
                                    numeric_limits<int>::max());
  a.resize(n);
  for (int i = 0; i < n; ++i) {
    a[i] = dis(gen);
  }
}

int cArray::demXuatHien(int x) const {
  int dem = 0;
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x)
      dem++;
  }
  return dem;
}

bool cArray::kiemTraTangDan() const {
  for (size_t i = 0; i + 1 < a.size(); ++i) {
    if (a[i] > a[i + 1])
      return false;
  }
  return true;
}

int cArray::timLeNhoNhat() const {
  int minLe = 0;
  bool found = false;
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] % 2 != 0) {
      if (!found || a[i] < minLe) {
        minLe = a[i];
        found = true;
      }
    }
  }
  if (!found) {
    cout << "Mang khong co so le.\n";
    return 0;
  }
  return minLe;
}

void cArray::sapXepTangDan() { sort(a.begin(), a.end()); }
