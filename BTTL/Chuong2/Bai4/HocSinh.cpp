#include "HocSinh.h"
#include <iostream>

using namespace std;

void HocSinh::nhap() {
  cout << "Nhap ma hoc sinh: ";
  getline(cin >> ws, maHS);
  cout << "Nhap ho va ten: ";
  getline(cin, hoTen);
  cout << "Nhap gioi tinh: ";
  getline(cin, gioiTinh);
  cout << "Nhap diem toan: ";
  cin >> diemToan;
  cout << "Nhap diem ly: ";
  cin >> diemLy;
  cout << "Nhap diem hoa: ";
  cin >> diemHoa;
}

double HocSinh::tinhDiemTrungBinh() const {
  return (diemToan + diemLy + diemHoa) / 3.0;
}

void HocSinh::xuat() const {
  cout << "Ma hoc sinh: " << maHS << "\n";
  cout << "Ho va ten: " << hoTen << "\n";
  cout << "Gioi tinh: " << gioiTinh << "\n";
  cout << "Diem toan: " << diemToan << "\n";
  cout << "Diem ly: " << diemLy << "\n";
  cout << "Diem hoa: " << diemHoa << "\n";
  cout << "Diem trung binh: " << tinhDiemTrungBinh() << "\n";
}
