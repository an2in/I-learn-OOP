#include "HocSinh.h"
#include <iostream>

using namespace std;

HocSinh::HocSinh() : hoTen(""), diemToan(0), diemVan(0) {}

void HocSinh::nhap() {
  cout << "Nhap ho va ten: ";
  getline(cin >> ws, hoTen);
  cout << "Nhap diem toan: ";
  cin >> diemToan;
  cout << "Nhap diem van: ";
  cin >> diemVan;
}

double HocSinh::tinhDiemTrungBinh() const { return (diemToan + diemVan) / 2.0; }

string HocSinh::xepLoai() const {
  double dtb = tinhDiemTrungBinh();
  if (dtb >= 9.9)
    return "dangcap";
  if (dtb >= 8.0)
    return "Gioi";
  if (dtb >= 6.5)
    return "Kha";
  if (dtb >= 5.0)
    return "Trung binh";
  return "Yeu";
}

void HocSinh::xuat() const {
  cout << "Ho va ten: " << hoTen << "\n";
  cout << "Diem toan: " << diemToan << "\n";
  cout << "Diem van: " << diemVan << "\n";
  cout << "Diem trung binh: " << tinhDiemTrungBinh() << "\n";
  cout << "Xep loai: " << xepLoai() << "\n";
}
