#include "NhanVien.h"
#include <iomanip>
#include <iostream>

using namespace std;

// ================= NhanVien =================
NhanVien::NhanVien(string ma, string ten, int t, string tel, string mail,
                   double lcb)
    : maNV(ma), hoTen(ten), tuoi(t), sdt(tel), email(mail), luongCoBan(lcb) {}

void NhanVien::nhap() {
  cout << "  Nhap ma nhan vien: ";
  getline(cin >> ws, maNV);
  cout << "  Nhap ho ten: ";
  getline(cin, hoTen);
  cout << "  Nhap tuoi: ";
  cin >> tuoi;
  cout << "  Nhap so dien thoai: ";
  getline(cin >> ws, sdt);
  cout << "  Nhap email: ";
  getline(cin, email);
  cout << "  Nhap luong co ban: ";
  cin >> luongCoBan;
}

void NhanVien::xuat() const {
  cout << "Ma NV: " << maNV << " | Ten: " << hoTen << " | Tuoi: " << tuoi
       << " | SDT: " << sdt << " | Email: " << email << " | LCB: " << fixed
       << setprecision(0) << luongCoBan;
}

double NhanVien::getLuongCoBan() const { return luongCoBan; }

// ================= LapTrinhVien =================
LapTrinhVien::LapTrinhVien(string ma, string ten, int t, string tel,
                           string mail, double lcb, int ot)
    : NhanVien(ma, ten, t, tel, mail, lcb), soGioOvertime(ot) {}

void LapTrinhVien::nhap() {
  NhanVien::nhap();
  cout << "  Nhap so gio overtime: ";
  cin >> soGioOvertime;
}

double LapTrinhVien::tinhLuong() const {
  return luongCoBan + soGioOvertime * 200000.0;
}

void LapTrinhVien::xuat() const {
  NhanVien::xuat();
  cout << " | OT: " << soGioOvertime << "h | Luong: " << fixed
       << setprecision(0) << tinhLuong() << " VND\n";
}

// ================= KiemChungVien =================
KiemChungVien::KiemChungVien(string ma, string ten, int t, string tel,
                             string mail, double lcb, int loi)
    : NhanVien(ma, ten, t, tel, mail, lcb), soLoi(loi) {}

void KiemChungVien::nhap() {
  NhanVien::nhap();
  cout << "  Nhap so loi phat hien: ";
  cin >> soLoi;
}

double KiemChungVien::tinhLuong() const {
  return luongCoBan + soLoi * 50000.0;
}

void KiemChungVien::xuat() const {
  NhanVien::xuat();
  cout << " | So loi: " << soLoi << " | Luong: " << fixed
       << setprecision(0) << tinhLuong() << " VND\n";
}

// ================= CongTy =================
void CongTy::nhap() {
  int n, m;
  cout << "Nhap so luong lap trinh vien: ";
  cin >> n;
  dsLTV.resize(n);
  for (int i = 0; i < n; ++i) {
    cout << "\nNhap thong tin lap trinh vien " << i + 1 << ":\n";
    dsLTV[i].nhap();
  }

  cout << "\nNhap so luong kiem chung vien: ";
  cin >> m;
  dsKCV.resize(m);
  for (int i = 0; i < m; ++i) {
    cout << "\nNhap thong tin kiem chung vien " << i + 1 << ":\n";
    dsKCV[i].nhap();
  }
}

void CongTy::xuat() const {
  cout << "\n--- DANH SACH LAP TRINH VIEN ---\n";
  for (size_t i = 0; i < dsLTV.size(); ++i) {
    dsLTV[i].xuat();
  }

  cout << "\n--- DANH SACH KIEM CHUNG VIEN ---\n";
  for (size_t i = 0; i < dsKCV.size(); ++i) {
    dsKCV[i].xuat();
  }
}

double CongTy::tinhLuongTrungBinh() const {
  size_t tongNV = dsLTV.size() + dsKCV.size();
  if (tongNV == 0)
    return 0.0;

  double tongLuong = 0;
  for (size_t i = 0; i < dsLTV.size(); ++i) {
    tongLuong += dsLTV[i].tinhLuong();
  }
  for (size_t i = 0; i < dsKCV.size(); ++i) {
    tongLuong += dsKCV[i].tinhLuong();
  }
  return tongLuong / tongNV;
}

void CongTy::xuatLuongDuoiTrungBinh() const {
  double luongTB = tinhLuongTrungBinh();
  cout << "\nMuc luong trung binh toan cong ty: " << fixed << setprecision(0)
       << luongTB << " VND\n";
  cout << "--- CAC NHAN VIEN CO LUONG THAP HON MUC TRUNG BINH ---\n";

  bool coNV = false;
  for (size_t i = 0; i < dsLTV.size(); ++i) {
    if (dsLTV[i].tinhLuong() < luongTB) {
      cout << "[LTV] ";
      dsLTV[i].xuat();
      coNV = true;
    }
  }
  for (size_t i = 0; i < dsKCV.size(); ++i) {
    if (dsKCV[i].tinhLuong() < luongTB) {
      cout << "[KCV] ";
      dsKCV[i].xuat();
      coNV = true;
    }
  }

  if (!coNV) {
    cout << "Khong co nhan vien nao co luong duoi muc trung binh.\n";
  }
}
