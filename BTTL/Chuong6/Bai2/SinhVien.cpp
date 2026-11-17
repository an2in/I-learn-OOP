#include "SinhVien.h"
#include <iomanip>
#include <iostream>

using namespace std;

// ================= SinhVien =================
SinhVien::SinhVien(string ma, string ten, string dc, int tinChi, double dtb)
    : mssv(ma), hoTen(ten), diaChi(dc), tongTinChi(tinChi), diemTB(dtb) {}

void SinhVien::nhap() {
  cout << "  Nhap ma so sinh vien: ";
  getline(cin >> ws, mssv);
  cout << "  Nhap ho ten: ";
  getline(cin, hoTen);
  cout << "  Nhap dia chi: ";
  getline(cin, diaChi);
  cout << "  Nhap tong so tin chi: ";
  cin >> tongTinChi;
  cout << "  Nhap diem trung binh: ";
  cin >> diemTB;
}

void SinhVien::xuat() const {
  cout << "MSSV: " << mssv << " | Ho ten: " << hoTen << " | Dia chi: " << diaChi
       << " | So tin chi: " << tongTinChi << " | DTB: " << fixed
       << setprecision(2) << diemTB;
}

// ================= SinhVienCaoDang =================
SinhVienCaoDang::SinhVienCaoDang(string ma, string ten, string dc, int tinChi,
                                 double dtb, double diemTN)
    : SinhVien(ma, ten, dc, tinChi, dtb), diemThiTotNghiep(diemTN) {}

void SinhVienCaoDang::nhap() {
  SinhVien::nhap();
  cout << "  Nhap diem thi tot nghiep: ";
  cin >> diemThiTotNghiep;
}

bool SinhVienCaoDang::duDieuKienTotNghiep() const {
  return (tongTinChi >= 120 && diemTB >= 5.0 && diemThiTotNghiep >= 5.0);
}

void SinhVienCaoDang::xuat() const {
  SinhVien::xuat();
  cout << " | Diem thi TN: " << fixed << setprecision(2) << diemThiTotNghiep
       << " | Tot nghiep: " << (duDieuKienTotNghiep() ? "DU DIEU KIEN" : "CHUA DU DIEU KIEN")
       << "\n";
}

// ================= SinhVienDaiHoc =================
SinhVienDaiHoc::SinhVienDaiHoc(string ma, string ten, string dc, int tinChi,
                               double dtb, string luanVan, double diemLV)
    : SinhVien(ma, ten, dc, tinChi, dtb), tenLuanVan(luanVan),
      diemLuanVan(diemLV) {}

void SinhVienDaiHoc::nhap() {
  SinhVien::nhap();
  cout << "  Nhap ten luan van: ";
  getline(cin >> ws, tenLuanVan);
  cout << "  Nhap diem luan van: ";
  cin >> diemLuanVan;
}

bool SinhVienDaiHoc::duDieuKienTotNghiep() const {
  return (tongTinChi >= 170 && diemTB >= 5.0 && diemLuanVan >= 5.0);
}

void SinhVienDaiHoc::xuat() const {
  SinhVien::xuat();
  cout << " | Ten LV: " << tenLuanVan << " | Diem LV: " << fixed
       << setprecision(2) << diemLuanVan
       << " | Tot nghiep: " << (duDieuKienTotNghiep() ? "DU DIEU KIEN" : "CHUA DU DIEU KIEN")
       << "\n";
}
