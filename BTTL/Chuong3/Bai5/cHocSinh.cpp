#include "cHocSinh.h"
#include <iostream>

using namespace std;

cHocSinh::cHocSinh() : ma(""), hoTen(""), gioiTinh(""), namSinh(0), diemTB(0) {}

void cHocSinh::nhap() {
  cout << "Nhap ma hoc sinh: ";
  getline(cin >> ws, ma);
  cout << "Nhap ho va ten: ";
  getline(cin, hoTen);
  cout << "Nhap gioi tinh: ";
  getline(cin, gioiTinh);
  cout << "Nhap nam sinh: ";
  cin >> namSinh;
  cout << "Nhap diem trung binh: ";
  cin >> diemTB;
}

void cHocSinh::xuat() const {
  cout << "Ma: " << ma << " | Ho ten: " << hoTen << " | Gioi tinh: " << gioiTinh
       << " | Nam sinh: " << namSinh << " | DTB: " << diemTB << "\n";
}

double cHocSinh::getDiemTB() const { return diemTB; }

int cHocSinh::getNamSinh() const { return namSinh; }

string cHocSinh::getHoTen() const { return hoTen; }
