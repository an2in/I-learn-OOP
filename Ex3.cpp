#include <iostream>
#include <string>
using namespace std;

class Hero {
private:
  string name;
  int hp;

public:
  static void displayEnter() { cout << "--- Entering Dugeon Block ---\n"; }
  static void displayOut() { cout << "--- Leaving dungeon block ---\n"; }
  Hero(string Hname, int Hhp) : name(Hname), hp(Hhp) {
    cout << "⚔️ Hero " << name << " enters the battle with " << hp << " HP!\n";
    // displayEnter();
  }

  Hero() : name("Nameless Wanderer"), hp(000) {
    cout << "Default Nameless Wanderer created!\n";
  }

  ~Hero() {
    cout << "💀 Hero " << name << " has fallen!\n";
    // displayOut();
  }
};

int main() {
  Hero h1("Arthur", 150);
  Hero::displayEnter();
  {
    Hero h2("Lancelot", 120);
    Hero h3;
  }
  Hero::displayOut();
  cout << "--- Leaving main()---\n";
  return 0;
}