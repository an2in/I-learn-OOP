#pragma once

#include <string>
#include <vector>

class cBook {
private:
  std::string maSach;
  std::string tenSach;
  int namXuatBan;
  int tongSoTrang;

public:
  cBook(std::string ma = "", std::string ten = "", int nam = 0, int trang = 0);
  void nhap();
  void xuat() const;

  std::string getMaSach() const;
  std::string getTenSach() const;
  int getNamXuatBan() const;
  int getTongSoTrang() const;
  void capNhat(std::string ten, int nam, int trang);
};

class cListBook {
private:
  std::vector<cBook> ds;

public:
  void nhap();
  void xuat() const;
  cBook timXuatBanGanNhat() const;
};
