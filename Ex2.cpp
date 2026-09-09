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

public:
  // Constructor
  Safe(string Owner, int SafeCode, double StoredCash)
      : owner(Owner), safeCode(SafeCode), storedCash(StoredCash) {}

  // Methods
  void deposit(double amount) {
    if (amount > 0) {
      storedCash += amount;
      cout << "Okay, done bro! " << storedCash << " ";
    } else
      cout << "Actually, I can (or not) deduct money from your account but the "
              "problem statement dont allow me to do that:D";
  }
  double GetCash() const { return storedCash; }
};
class MasterSafe : public Safe {
public:
  // Constructor
  MasterSafe(string o, int s, double sC) : Safe(o, s, sC) {}
  void changeCode(int newCode) { safeCode = newCode; }
};
int main() {
  MasterSafe Test("Alice", 0, 1000);
  Test.deposit(1000);
  Test.changeCode(12);
  cout << Test.owner << "\n";
}