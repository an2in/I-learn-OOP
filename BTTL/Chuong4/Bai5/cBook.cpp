#include "cBook.h"
#include <iostream>

using namespace std;

// ================= cBook =================
cBook::cBook(string ma, string ten, int nam, int trang)
    : maSach(ma), tenSach(ten), namXuatBan(nam), tongSoTrang(trang) {}

void cBook::nhap() {
  cout << "  Nhap ma sach: ";
  getline(cin >> ws, maSach);
  cout << "  Nhap ten sach: ";
  getline(cin, tenSach);
  cout << "  Nhap nam xuat ban: ";
  cin >> namXuatBan;
  cout << "  Nhap tong so trang: ";
  cin >> tongSoTrang;
}

void cBook::xuat() const {
  cout << "Ma sach: " << maSach << " | Ten sach: " << tenSach
       << " | Nam XB: " << namXuatBan << " | So trang: " << tongSoTrang << "\n";
}

string cBook::getMaSach() const { return maSach; }
string cBook::getTenSach() const { return tenSach; }
int cBook::getNamXuatBan() const { return namXuatBan; }
int cBook::getTongSoTrang() const { return tongSoTrang; }

void cBook::capNhat(string ten, int nam, int trang) {
  tenSach = ten;
  namXuatBan = nam;
  tongSoTrang = trang;
}

// ================= cListBook =================
void cListBook::nhap() {
  int n;
  cout << "Nhap so luong sach: ";
  cin >> n;
  ds.resize(n);
  for (int i = 0; i < n; ++i) {
    cout << "\nNhap thong tin cuon sach " << i + 1 << ":\n";
    ds[i].nhap();
  }
}

void cListBook::xuat() const {
  for (size_t i = 0; i < ds.size(); ++i) {
    ds[i].xuat();
  }
}

cBook cListBook::timXuatBanGanNhat() const {
  if (ds.empty())
    return cBook();
  cBook newest = ds[0];
  for (size_t i = 1; i < ds.size(); ++i) {
    if (ds[i].getNamXuatBan() > newest.getNamXuatBan()) {
      newest = ds[i];
    }
  }
  return newest;
}
