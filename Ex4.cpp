#include <iostream>
using namespace std;
class Thermostat {
private:
  double celsius;

public:
  bool isValidCelsius(double c) {
    if (c >= -273.15)
      return true;
    else
      return false;
  }
  void setCelsius(double c) {
    cout << "Setting temperature to " << c << " C...\n";
    if (isValidCelsius(c))
      celsius = c;
    else {
      cout << "Bro, you are destroying the universe\n";
    }
  }
  Thermostat(double initialCelsius) {
    cout << "Setting temperature to " << initialCelsius << "C...\n";
    if (isValidCelsius(initialCelsius)) {
      celsius = initialCelsius;
    } else {
      celsius = 20;
      cout << "Bro, you are destroying the universe\n";
    }
  }
  void getCelsius() const { cout << "Celsius: " << celsius << " C\n"; }
  void getFahrenheit() const {
    cout << "Fahrenheit: " << celsius * 9.0 / 5.0 + 32.0 << " F\n";
  }
  void getKelvin() const { cout << "Kelvin: " << celsius + 273.15 << " K\n"; }
};
int main() {
  Thermostat MyDaikin(25);
  MyDaikin.getCelsius();
  MyDaikin.getFahrenheit();
  MyDaikin.getKelvin();
  MyDaikin.setCelsius(-300);
  cout << "Current temp: ";
  MyDaikin.getCelsius();
}