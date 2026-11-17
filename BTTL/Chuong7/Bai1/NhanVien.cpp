#include "NhanVien.h"
#include <iomanip>
#include <iostream>

using namespace std;

// ================= NhanVien =================
NhanVien::NhanVien(string ten, string ns, double lcb)
    : hoTen(ten), ngaySinh(ns), luongCoBan(lcb) {}

void NhanVien::nhap() {
  cout << "  Nhap ho ten: ";
  getline(cin >> ws, hoTen);
  cout << "  Nhap ngay sinh (dd/mm/yyyy): ";
  getline(cin, ngaySinh);
  cout << "  Nhap luong co ban: ";
  cin >> luongCoBan;
}

void NhanVien::xuat() const {
  cout << "Ho ten: " << hoTen << " | Ngay sinh: " << ngaySinh
       << " | LCB: " << fixed << setprecision(0) << luongCoBan;
}

string NhanVien::getHoTen() const { return hoTen; }

// ================= NhanVienVanPhong =================
NhanVienVanPhong::NhanVienVanPhong(string ten, string ns, double lcb, int soNgay,
                                   double tc)
    : NhanVien(ten, ns, lcb), soNgayLamViec(soNgay), troCap(tc) {}

void NhanVienVanPhong::nhap() {
  NhanVien::nhap();
  cout << "  Nhap so ngay lam viec: ";
  cin >> soNgayLamViec;
  cout << "  Nhap tro cap: ";
  cin >> troCap;
}

double NhanVienVanPhong::tinhLuong() const {
  return luongCoBan + soNgayLamViec * 200000.0 + troCap;
}

void NhanVienVanPhong::xuat() const {
  cout << "[Van phong] ";
  NhanVien::xuat();
  cout << " | So ngay lam: " << soNgayLamViec << " | Tro cap: " << fixed
       << setprecision(0) << troCap << " | Luong: " << fixed << setprecision(0)
       << tinhLuong() << " VND\n";
}

// ================= NhanVienSanXuat =================
NhanVienSanXuat::NhanVienSanXuat(string ten, string ns, double lcb, int soSP)
    : NhanVien(ten, ns, lcb), soSanPham(soSP) {}

void NhanVienSanXuat::nhap() {
  NhanVien::nhap();
  cout << "  Nhap so san pham: ";
  cin >> soSanPham;
}

double NhanVienSanXuat::tinhLuong() const {
  return luongCoBan + soSanPham * 2000.0;
}

void NhanVienSanXuat::xuat() const {
  cout << "[San xuat]  ";
  NhanVien::xuat();
  cout << " | So san pham: " << soSanPham << " | Luong: " << fixed
       << setprecision(0) << tinhLuong() << " VND\n";
}

// ================= NhanVienQuanLy =================
NhanVienQuanLy::NhanVienQuanLy(string ten, string ns, double lcb, double heSo,
                               double th)
    : NhanVien(ten, ns, lcb), heSoChucVu(heSo), thuong(th) {}

void NhanVienQuanLy::nhap() {
  NhanVien::nhap();
  cout << "  Nhap he so chuc vu: ";
  cin >> heSoChucVu;
  cout << "  Nhap tien thuong: ";
  cin >> thuong;
}

double NhanVienQuanLy::tinhLuong() const {
  return luongCoBan * heSoChucVu + thuong;
}

void NhanVienQuanLy::xuat() const {
  cout << "[Quan ly]   ";
  NhanVien::xuat();
  cout << " | He so CV: " << fixed << setprecision(2) << heSoChucVu
       << " | Thuong: " << fixed << setprecision(0) << thuong
       << " | Luong: " << fixed << setprecision(0) << tinhLuong() << " VND\n";
}

// ================= CongTyABC =================
CongTyABC::~CongTyABC() {
  for (NhanVien *nv : ds) {
    delete nv;
  }
  ds.clear();
}

void CongTyABC::nhap() {
  int n;
  cout << "Nhap so luong nhan vien: ";
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cout << "\nChon loai nhan vien thu " << i + 1 << ":\n";
    cout << "  1. Nhan vien Van phong\n";
    cout << "  2. Nhan vien San xuat\n";
    cout << "  3. Nhan vien Quan ly\n";
    cout << "  Lua chon (1-3): ";
    int loai;
    cin >> loai;

    NhanVien *nv = nullptr;
    if (loai == 1) {
      nv = new NhanVienVanPhong();
    } else if (loai == 2) {
      nv = new NhanVienSanXuat();
    } else if (loai == 3) {
      nv = new NhanVienQuanLy();
    } else {
      cout << "Lua chon khong hop le, mac dinh chon Van phong.\n";
      nv = new NhanVienVanPhong();
    }

    nv->nhap();
    ds.push_back(nv);
  }
}

void CongTyABC::xuat() const {
  cout << "\n--- DANH SACH NHAN VIEN CONG TY ABC ---\n";
  for (size_t i = 0; i < ds.size(); ++i) {
    cout << i + 1 << ". ";
    ds[i]->xuat();
  }
}

double CongTyABC::tinhTongLuong() const {
  double tong = 0;
  for (const NhanVien *nv : ds) {
    tong += nv->tinhLuong();
  }
  return tong;
}

void CongTyABC::timKiemTheoTen(const string &ten) const {
  cout << "\n--- KET QUA TIM KIEM THEO TEN: \"" << ten << "\" ---\n";
  bool timThay = false;
  for (size_t i = 0; i < ds.size(); ++i) {
    if (ds[i]->getHoTen().find(ten) != string::npos) {
      cout << "- ";
      ds[i]->xuat();
      timThay = true;
    }
  }
  if (!timThay) {
    cout << "Khong tim thay nhan vien nao phu hop.\n";
  }
}
