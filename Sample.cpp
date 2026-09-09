#include <iostream>
#include <string>

// 1. Blueprint (Class)
class Person {
private:
    // Encapsulation: private attributes cannot be modified directly from outside
    std::string name;
    int age;

public:
    // Constructor: automatically called when a Person is created
    Person(std::string personName, int personAge)
        : name(personName), age(personAge) {}

    // Getter
    std::string getName() const {
        return name;
    }

    // Getter
    int getAge() const {
        return age;
    }

    // Setter with validation
    void setAge(int newAge) {
        if (newAge > 0) {
            age = newAge;
        } else {
            std::cout << "Invalid age!\n";
        }
    }

    // Member function (Behavior)
    void introduce() const {
        std::cout << "Hi! My name is " << name << " and I am " << age << " years old.\n";
    }
};

int main() {
    // 2. Creating an Object (Instance)
    Person person1("Alice", 20);
    Person person2("Bob", 25);

    // 3. Calling behaviors
    person1.introduce();
    person2.introduce();

    // 4. Using encapsulated methods
    person1.setAge(21);
    std::cout << person1.getName() << "'s updated age: " << person1.getAge() << "\n";

    return 0;
}