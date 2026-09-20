#include <iostream>
#include <string>
using namespace std;
class Vehicle {
protected:
  string brand;
  int speed;

public:
  Vehicle(string Brand, int Speed) : brand(Brand), speed(Speed) {}
  void acclerate(int amount) {
    speed += amount;
    cout << "Acceleratinggggggggggggg...\n"
         << "Current speed: " << speed << "km/h\n";
  }
};
class EVCar : public Vehicle {
private:
  int Battery;

public:
  EVCar(string BRAND, int SPEED, int BATTERY)
      : Vehicle(BRAND, SPEED), Battery(BATTERY) {}
  void charge(int percent) {
    Battery += percent;
    if (Battery >= 100) {
      Battery = 100;
      cout << "Battery is fully charged";
    } else
      cout << "Battery charged to " << Battery << "%\n";
  }
  void showStatus() const {
    cout << "Brand name: " << brand << " | Battery: " << Battery
         << " | Speed: " << speed << "\n";
  }
};
int main() {
  EVCar Elon("Tesla", 200, 10);
  Elon.showStatus();
  Elon.acclerate(300);
  Elon.charge(56);
  Elon.showStatus();
  return 0;
}