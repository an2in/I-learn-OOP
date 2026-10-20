#include "arrPhanSo.h"
#include <iostream>

using namespace std;

int main() {
  arrPhanSo ds;
  ds.nhap();

  cout << "\nDanh sach phan so vua nhap: ";
  ds.xuat();

  cout << "Phan so co gia tri lon nhat: ";
  ds.timMax().xuat();
  cout << "\n";

  cout << "So luong phan so co tu la so nguyen to: " << ds.demTuNguyenTo()
       << "\n";

  cout << "Danh sach sau khi sap xep tang dan: ";
  ds.sapXepTangDan();
  ds.xuat();

  return 0;
}
