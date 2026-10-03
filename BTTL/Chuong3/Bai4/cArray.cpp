#include "cArray.h"
#include <algorithm>
#include <iostream>
#include <limits>
#include <random>

using namespace std;

cArray::cArray(int n) {
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<int> dis(
      numeric_limits<int>::min(),
      numeric_limits<int>::max()); // gen so ngau nhien sieu cap
  a.resize(n);
  for (int i = 0; i < n; ++i) {
    a[i] = dis(gen);
  }
}

void cArray::xuat() const {
  for (size_t i = 0; i < a.size(); ++i) {
    cout << a[i] << " ";
  }
  cout << "\n";
}

int cArray::timAmLonNhat() const {
  int maxAm = 0;
  bool found = false;
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] < 0) {
      if (!found || a[i] > maxAm) {
        maxAm = a[i];
        found = true;
      }
    }
  }
  if (!found) {
    cout << "Mang khong co so am ban ey.\n";
    return 0;
  }
  return maxAm;
}

int cArray::demXuatHien(int x) const {
  int dem = 0;
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x)
      dem++;
  }
  return dem;
}

bool cArray::kiemTraGiamDan() const {
  for (size_t i = 0; i + 1 < a.size(); ++i) {
    if (a[i] < a[i + 1])
      return false;
  }
  return true;
}

void cArray::sapXepTangDan() { sort(a.begin(), a.end()); } // hihi
