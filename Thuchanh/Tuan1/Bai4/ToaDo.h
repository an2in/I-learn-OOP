// #pragma once
// class ToaDo {
// private:
//   double hoanhdo, tungdo;

// public:
//   ToaDo(double hoanhdo = 0.0, double tungdo = 0.0);
//   ~ToaDo();
//   void ThayDoi(double xMoi, double yMoi);
//   void TinhTien(double dx, double dy);
//   double LayHoanhDo() const;
//   double LayTungDo() const;
//   void Nhap();
//   void Xuat() const;
// };

#pragma once
class Diem {
private:
  float hoanhdo, tungdo;

public:
  Diem(float hoanhdo = 0.0, float tungdo = 0.0);
  ~Diem();
  void doiTungDo(float yMoi);
  void doiHoanhDo(float xMoi);
  float layTungdo() const;
  float layHoanhDo() const;
  void TinhTien(float dx, float dy);
  void nhapDiem();
  void xuatDiem() const;
};