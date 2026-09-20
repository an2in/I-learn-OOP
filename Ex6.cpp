#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Character {
protected:
  string name;

public:
  Character(string Name) : name(Name) {}
  virtual void attack() const {}
  virtual ~Character() {}
};
class Warrior : public Character {
public:
  Warrior(string NAME) : Character(NAME) {}
  void attack() const override {
    cout << name << " swings a colossal Battle Axe!\n";
  }
};
class Mage : public Character {
public:
  Mage(string NAME) : Character(NAME) {}
  void attack() const override {
    cout << name << " launches a Meteor Strike!\n";
  }
};
class Ranger : public Character {
public:
  Ranger(string NAME) : Character(NAME) {}
  void attack() const override {
    cout << name << " fires a Volley of Poison Arrows!\n";
  }
};
int main() {
  vector<Character *> Cha;
  Cha.push_back(new Warrior("G"));
  Cha.push_back(new Ranger("Y"));
  Cha.push_back(new Mage("A"));
  for (Character *cha : Cha) {
    cha->attack();
  }
  for (Character *cha : Cha) {
    delete cha;
  }
  return 0;
}
