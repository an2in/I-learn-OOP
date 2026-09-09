#include <iostream>
#include <string>
using namespace std;
class Safe {
  // Atrributes
public:
  string owner;

protected:
  int safeCode;

private:
  double storedCash;

  // Constructor
  Safe(string Owner, int SafeCode, double StoredCash)
      : owner(Owner), safeCode(SafeCode), storedCash(StoredCash) {}

  // Methods
  void deposit(double amount) {
    if (amount > 0)
      storedCash += amount;
    else
      cout << "Actually, I can (or not) deduct money from your account but the "
              "problem statement dont allow me to do that:D";
  }
  double GetCash() const { return storedCash; }
};
int main() {}