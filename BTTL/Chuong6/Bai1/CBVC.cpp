#include "CBVC.h"
#include <iomanip>
#include <iostream>

using namespace std;

// ================= CBVC =================
CBVC::CBVC(string ma, string ten, string phai)
    : maCB(ma), hoTen(ten), gioiTinh(phai) {}

void CBVC::nhap() {
  cout << "  Nhap ma can bo: ";
  getline(cin >> ws, maCB);
  cout << "  Nhap ho ten: ";
  getline(cin, hoTen);
  cout << "  Nhap gioi tinh: ";
  getline(cin, gioiTinh);
}

void CBVC::xuat() const {
  cout << "Ma: " << maCB << " | Ho ten: " << hoTen
       << " | Gioi tinh: " << gioiTinh;
}

// ================= GiangVien =================
GiangVien::GiangVien(string ma, string ten, string phai, int day, int nc)
    : CBVC(ma, ten, phai), soGioDay(day), soGioNC(nc) {}

void GiangVien::nhap() {
  CBVC::nhap();
  cout << "  Nhap so gio day: ";
  cin >> soGioDay;
  cout << "  Nhap so gio nghien cuu: ";
  cin >> soGioNC;
}

double GiangVien::tinhLuong(double donGia) const {
  return (soGioDay + soGioNC) * donGia;
}

void GiangVien::xuat() const {
  CBVC::xuat();
  cout << " | Gio day: " << soGioDay << " | Gio NC: " << soGioNC
       << " | Luong: " << fixed << setprecision(0) << tinhLuong() << " VND\n";
}

// ================= NhanVienHanhChinh =================
NhanVienHanhChinh::NhanVienHanhChinh(string ma, string ten, string phai,
                                     int ngay, int them)
    : CBVC(ma, ten, phai), soNgayLamViec(ngay), soGioLamThem(them) {}

void NhanVienHanhChinh::nhap() {
  CBVC::nhap();
  cout << "  Nhap so ngay lam viec: ";
  cin >> soNgayLamViec;
  cout << "  Nhap so gio lam them: ";
  cin >> soGioLamThem;
}

double NhanVienHanhChinh::tinhLuong(double tienCongNgay, double donGiaThem) const {
  return soNgayLamViec * tienCongNgay + soGioLamThem * donGiaThem;
}

void NhanVienHanhChinh::xuat() const {
  CBVC::xuat();
  cout << " | So ngay lam: " << soNgayLamViec << " | Gio lam them: " << soGioLamThem
       << " | Luong: " << fixed << setprecision(0) << tinhLuong() << " VND\n";
}

// ================= QuanLyCBVC =================
void QuanLyCBVC::nhap() {
  int n, m;
  cout << "Nhap so luong giang vien: ";
  cin >> n;
  dsGV.resize(n);
  for (int i = 0; i < n; ++i) {
    cout << "\nNhap thong tin giang vien " << i + 1 << ":\n";
    dsGV[i].nhap();
  }

  cout << "\nNhap so luong nhan vien hanh chinh: ";
  cin >> m;
  dsNVHC.resize(m);
  for (int i = 0; i < m; ++i) {
    cout << "\nNhap thong tin nhan vien hanh chinh " << i + 1 << ":\n";
    dsNVHC[i].nhap();
  }
}

void QuanLyCBVC::xuat() const {
  cout << "\n--- DANH SACH GIANG VIEN ---\n";
  for (size_t i = 0; i < dsGV.size(); ++i) {
    dsGV[i].xuat();
  }

  cout << "\n--- DANH SACH NHAN VIEN HANH CHINH ---\n";
  for (size_t i = 0; i < dsNVHC.size(); ++i) {
    dsNVHC[i].xuat();
  }
}

double QuanLyCBVC::tinhTongLuong() const {
  double tong = 0;
  for (size_t i = 0; i < dsGV.size(); ++i) {
    tong += dsGV[i].tinhLuong();
  }
  for (size_t i = 0; i < dsNVHC.size(); ++i) {
    tong += dsNVHC[i].tinhLuong();
  }
  return tong;
}
