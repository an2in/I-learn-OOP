# Object-Oriented Programming (OOP) in C++: Beginner to Mastery

Welcome to the complete beginner's guide to **Object-Oriented Programming (OOP)** in C++. This guide explains every concept from scratch using plain language, runnable code examples, and their exact expected outputs.

---

## Table of Contents
1. [What is OOP?](#1-what-is-oop)
2. [Classes and Objects](#2-classes-and-objects)
3. [Access Specifiers (`public`, `private`, `protected`)](#3-access-specifiers)
4. [Constructors and Destructors](#4-constructors-and-destructors)
5. [The 4 Pillars of OOP](#5-the-4-pillars-of-oop)
   - [Pillar 1: Encapsulation](#pillar-1-encapsulation)
   - [Pillar 2: Inheritance](#pillar-2-inheritance)
   - [Pillar 3: Polymorphism](#pillar-3-polymorphism)
   - [Pillar 4: Abstraction](#pillar-4-abstraction)
6. [Useful C++ OOP Best Practices](#6-useful-c-oop-best-practices)
7. [How to Compile and Run](#7-how-to-compile-and-run)
8. [Hands-on Practice Exercises by Section](#8-hands-on-practice-exercises-by-section)
   - [Exercise 1: Classes and Objects (Book Catalog)](#exercise-1-classes-and-objects-book-catalog)
   - [Exercise 2: Access Specifiers (Bank Vault)](#exercise-2-access-specifiers-bank-vault)
   - [Exercise 3: Constructors & Destructors (Hero Lifecycle)](#exercise-3-constructors--destructors-hero-lifecycle)
   - [Exercise 4: Encapsulation (Smart Thermostat)](#exercise-4-encapsulation-smart-thermostat)
   - [Exercise 5: Inheritance (Electric Vehicle)](#exercise-5-inheritance-electric-vehicle)
   - [Exercise 6: Polymorphism (RPG Combat Squad)](#exercise-6-polymorphism-rpg-combat-squad)
   - [Exercise 7: Abstraction (Notification Gateway)](#exercise-7-abstraction-notification-gateway)
   - [Capstone Challenge: Mini Inventory System](#capstone-challenge-mini-inventory-system)
9. [University Exam-Style Challenges (Requirements Only)](#9-university-exam-style-challenges-requirements-only)
   - [Challenge 1: Complex Number Arithmetic (`SoPhuc`) with Operator Overloading](#challenge-1-complex-number-arithmetic-sophuc-with-operator-overloading)
   - [Challenge 2: Cultivator & Combat Skill Hierarchy System (`Tu Si & Ky Nang`)](#challenge-2-cultivator--combat-skill-hierarchy-system-tu-si--ky-nang)
   - [Challenge 3: Resort Room Booking & Amenity Billing System](#challenge-3-resort-room-booking--amenity-billing-system)
   - [Challenge 4: Logistics Fleet & Highway Toll Checkpoint Dispatcher](#challenge-4-logistics-fleet--highway-toll-checkpoint-dispatcher)

---

## 1. What is OOP?

In **procedural programming** (basic C style), programs are written as a list of functions operating on detached data.
In **Object-Oriented Programming (OOP)**, programs are modeled around **objects**—bundles of **data (attributes)** and **functions (behaviors)** that represent real-world entities.

### Key Analogy: Blueprint vs. House
- **Class**: The **blueprint** drawn on paper. It defines the layout, number of rooms, and materials, but you cannot live in a blueprint.
- **Object**: The actual **house** built on physical ground according to that blueprint. You can build 10 different houses from the same single blueprint.

---

## 2. Classes and Objects

### Basic Syntax

```cpp
#include <iostream>
#include <string>

// Definition of the blueprint
class Car {
public:
    // Attributes (state / data)
    std::string brand;
    std::string model;
    int year;

    // Method (behavior / member function)
    void startEngine() {
        std::cout << brand << " " << model << " engine started: Vroom vroom!\n";
    }
};

int main() {
    // Instantiating objects from the Car blueprint
    Car car1;
    car1.brand = "Toyota";
    car1.model = "Corolla";
    car1.year = 2022;

    Car car2;
    car2.brand = "Tesla";
    car2.model = "Model 3";
    car2.year = 2024;

    // Calling methods using the dot (.) operator
    car1.startEngine();
    car2.startEngine();

    return 0;
}
```

**Program Output:**
```text
Toyota Corolla engine started: Vroom vroom!
Tesla Model 3 engine started: Vroom vroom!
```

> [!NOTE]
> In C++, every class declaration must end with a semicolon `;` after the closing curly brace.

---

## 3. Access Specifiers (`public`, `private`, `protected`)

Access specifiers determine the **visibility** and **security** of class members (variables and methods).

### The Access Matrix

| Access Specifier | Inside the Class itself? | Inside Derived (Child) Classes? | Outside (`main()` / other code)? |
| :--- | :---: | :---: | :---: |
| `public` | ✅ **Yes** | ✅ **Yes** | ✅ **Yes** |
| `protected` | ✅ **Yes** | ✅ **Yes** | ❌ **No** (Compile error) |
| `private` *(default)* | ✅ **Yes** | ❌ **No** (Compile error) | ❌ **No** (Compile error) |

---

### Complete Example Demonstrating All Three

```cpp
#include <iostream>
#include <string>

// Base class (Parent)
class Employee {
public:
    std::string name; // PUBLIC: Anyone can see and change this

protected:
    double salary;    // PROTECTED: Only Employee and derived classes (like Manager) can access

private:
    std::string ssn;  // PRIVATE: Strictly locked inside Employee (not even Manager can access!)

public:
    // Constructor
    Employee(std::string empName, double empSalary, std::string empSsn)
        : name(empName), salary(empSalary), ssn(empSsn) {}

    // Public method inside Employee can access everything, including private 'ssn'
    void printBadge() const {
        std::cout << "[Badge] Name: " << name 
                  << " | SSN: ***-**-" << ssn.substr(ssn.length() - 4) << "\n";
    }
};

// Derived class (Child)
class Manager : public Employee {
public:
    std::string department;

    Manager(std::string mgrName, double mgrSalary, std::string mgrSsn, std::string dept)
        : Employee(mgrName, mgrSalary, mgrSsn), department(dept) {}

    void giveRaise(double bonus) {
        // ALLOWED: 'salary' is protected, so derived classes can read/write it
        salary += bonus;
        std::cout << name << " got a raise! New Salary: $" << salary << "\n";
    }

    void inspectMembers() const {
        // 1. name is public -> ALLOWED
        std::cout << "Name: " << name << "\n";

        // 2. salary is protected -> ALLOWED
        std::cout << "Salary: " << salary << "\n";

        // 3. ssn is private to Employee -> COMPILE ERROR if uncommented!
        // std::cout << "SSN: " << ssn << "\n";
        // Error: 'std::string Employee::ssn' is private within this context
    }
};

int main() {
    Manager mgr("Sarah Connor", 85000.0, "123-45-6789", "Security");

    // ------------------------------------------------------------
    // 1. PUBLIC: Accessible everywhere
    // ------------------------------------------------------------
    std::cout << "Public Name: " << mgr.name << "\n";       // OK!
    std::cout << "Department: " << mgr.department << "\n";  // OK!

    // ------------------------------------------------------------
    // 2. PROTECTED: NOT accessible from main()
    // ------------------------------------------------------------
    // mgr.salary = 90000.0; // COMPILE ERROR: 'salary' is protected!
    mgr.giveRaise(5000.0);   // OK: Controlled through a public method

    // ------------------------------------------------------------
    // 3. PRIVATE: NOT accessible from main()
    // ------------------------------------------------------------
    // mgr.ssn = "000-00-0000"; // COMPILE ERROR: 'ssn' is private!
    mgr.printBadge();        // OK: Controlled through a public method

    return 0;
}
```

**Program Output:**
```text
Public Name: Sarah Connor
Department: Security
Sarah Connor got a raise! New Salary: $90000
[Badge] Name: Sarah Connor | SSN: ***-**-6789
```

---

### Quick Rule of Thumb: When to Use Which?

1. Use **`private`** by default for member variables (attributes). This protects your data from being corrupted from the outside.
2. Use **`public`** for methods (behaviors, getters, setters) that users of your class need to call.
3. Use **`protected`** when building inheritance hierarchies and you want child classes to have direct access to internal variables or helper methods without exposing them to the outside world.

---

## 4. Constructors and Destructors

Manually setting every variable after creating an object is repetitive. **Constructors** initialize an object automatically upon creation, and **Destructors** clean up when an object is destroyed.

### Parameterized Constructor & Initializer List
```cpp
#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    int id;

public:
    // Constructor using Member Initializer List (preferred C++ style)
    Student(std::string studentName, int studentId)
        : name(studentName), id(studentId) {
        std::cout << "Student " << name << " created!\n";
    }

    // Default Constructor (no parameters)
    Student() : name("Unknown"), id(0) {
        std::cout << "Student Unknown created!\n";
    }

    // Destructor: Called automatically when the object goes out of scope
    ~Student() {
        std::cout << "Student " << name << " destroyed!\n";
    }

    void displayInfo() const {
        std::cout << "ID: " << id << " | Name: " << name << "\n";
    }
};

int main() {
    Student s1("Alice", 101);
    s1.displayInfo();

    Student s2; // Calls default constructor
    s2.displayInfo();

    return 0; // When main exits, local variables are destroyed in reverse order
}
```

**Program Output:**
```text
Student Alice created!
ID: 101 | Name: Alice
Student Unknown created!
ID: 0 | Name: Unknown
Student Unknown destroyed!
Student Alice destroyed!
```

> [!TIP]
> Notice the destruction order: `s2` is destroyed before `s1`. In C++, objects created on the stack are destroyed in **reverse order of creation** (Last-In, First-Out).

---

## 5. The 4 Pillars of OOP

```
       +-----------------------------------------+
       |           4 Pillars of OOP              |
       +-----------------------------------------+
       | 1. Encapsulation (Data Protection)      |
       | 2. Inheritance   (Code Reusability)     |
       | 3. Polymorphism  (Multiple Forms)       |
       | 4. Abstraction   (Hiding Complexity)    |
       +-----------------------------------------+
```

---

### Pillar 1: Encapsulation

**Encapsulation** means bundling data and methods inside a single unit (the class), while keeping sensitive data **private** to prevent direct, unauthorized modification.

Access is mediated through **Getters** (read) and **Setters** (validate & write).

```cpp
#include <iostream>

class BankAccount {
private:
    double balance; // Cannot be accessed directly from main()

public:
    BankAccount(double initialBalance) {
        if (initialBalance >= 0) {
            balance = initialBalance;
        } else {
            balance = 0;
        }
    }

    // Setter with validation logic
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Successfully deposited $" << amount << "\n";
        } else {
            std::cout << "Invalid deposit amount!\n";
        }
    }

    // Getter
    double getBalance() const {
        return balance;
    }
};

int main() {
    BankAccount account(500.0);

    // account.balance = -999999; // COMPILE ERROR: balance is private!
    account.deposit(250.0);
    std::cout << "Current Balance: $" << account.getBalance() << "\n";

    return 0;
}
```

**Program Output:**
```text
Successfully deposited $250
Current Balance: $750
```

---

### Pillar 2: Inheritance

**Inheritance** allows a new class (**Derived / Child**) to reuse properties and methods of an existing class (**Base / Parent**). This promotes DRY ("Don't Repeat Yourself") code.

```cpp
#include <iostream>
#include <string>

// Base Class (Parent)
class Animal {
protected:
    std::string name; // protected: accessible by child classes

public:
    Animal(std::string animalName) : name(animalName) {}

    void eat() const {
        std::cout << name << " is eating food.\n";
    }
};

// Derived Class (Child inherits from Animal)
class Dog : public Animal {
private:
    std::string breed;

public:
    // Call the parent constructor in the initializer list
    Dog(std::string dogName, std::string dogBreed)
        : Animal(dogName), breed(dogBreed) {}

    void bark() const {
        std::cout << name << " (" << breed << ") says: Woof! Woof!\n";
    }
};

int main() {
    Dog myDog("Buddy", "Golden Retriever");
    myDog.eat();  // Inherited from Animal
    myDog.bark(); // Defined in Dog

    return 0;
}
```

**Program Output:**
```text
Buddy is eating food.
Buddy (Golden Retriever) says: Woof! Woof!
```

---

### Pillar 3: Polymorphism

**Polymorphism** means *"having many forms"*. It allows you to treat different derived objects through a common base pointer or reference.

#### 1. Compile-Time Polymorphism (Function Overloading)
Multiple functions with the same name but different parameter lists:

```cpp
#include <iostream>

class Calculator {
public:
    int add(int a, int b) { return a + b; }
    double add(double a, double b) { return a + b; }
    int add(int a, int b, int c) { return a + b + c; }
};

int main() {
    Calculator calc;
    std::cout << "add(10, 20)       = " << calc.add(10, 20) << "\n";
    std::cout << "add(2.5, 4.5)     = " << calc.add(2.5, 4.5) << "\n";
    std::cout << "add(1, 2, 3)      = " << calc.add(1, 2, 3) << "\n";
    return 0;
}
```

**Program Output:**
```text
add(10, 20)       = 30
add(2.5, 4.5)     = 7
add(1, 2, 3)      = 6
```

#### 2. Runtime Polymorphism (`virtual` and `override`)
When a child class redefines a base class function, declaring it `virtual` in the base class ensures the **correct child version** is called, even when accessed via a pointer or reference to the base class:

```cpp
#include <iostream>
#include <vector>

class Shape {
public:
    // Virtual function enables runtime dynamic dispatch
    virtual void draw() const {
        std::cout << "Drawing a generic shape.\n";
    }

    // Always make base destructor virtual when using inheritance
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a Circle 🟢\n";
    }
};

class Rectangle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a Rectangle 🟦\n";
    }
};

int main() {
    // Array of base class pointers pointing to different child objects
    std::vector<Shape*> shapes;
    shapes.push_back(new Circle());
    shapes.push_back(new Rectangle());
    shapes.push_back(new Circle());

    for (Shape* s : shapes) {
        s->draw(); // Dynamically calls Circle::draw or Rectangle::draw!
    }

    // Cleanup memory
    for (Shape* s : shapes) {
        delete s;
    }

    return 0;
}
```

**Program Output:**
```text
Drawing a Circle 🟢
Drawing a Rectangle 🟦
Drawing a Circle 🟢
```

---

### Pillar 4: Abstraction

**Abstraction** means showing only the essential features to the outside world while hiding the complex underlying details.

In C++, abstraction is achieved using **Abstract Classes** and **Pure Virtual Functions** (`= 0`). An abstract class cannot be instantiated directly; it serves as a strict contract/interface that derived classes must implement.

```cpp
#include <iostream>

// Abstract Class / Interface
class PaymentProcessor {
public:
    // Pure virtual function: No implementation here!
    virtual void processPayment(double amount) = 0;

    virtual ~PaymentProcessor() {}
};

class CreditCardPayment : public PaymentProcessor {
public:
    void processPayment(double amount) override {
        std::cout << "Processing $" << amount << " via Credit Card Gateway...\n";
    }
};

class PayPalPayment : public PaymentProcessor {
public:
    void processPayment(double amount) override {
        std::cout << "Processing $" << amount << " via PayPal API...\n";
    }
};

void checkout(PaymentProcessor& paymentMethod, double total) {
    // checkout() doesn't need to know HOW payment is processed, only that it CAN be
    paymentMethod.processPayment(total);
}

int main() {
    CreditCardPayment cc;
    PayPalPayment paypal;

    checkout(cc, 89.99);
    checkout(paypal, 19.50);

    return 0;
}
```

**Program Output:**
```text
Processing $89.99 via Credit Card Gateway...
Processing $19.5 via PayPal API...
```

---

## 6. Useful C++ OOP Best Practices

1. **Pass by Reference to Const (`const ClassName&`)**:
   Avoid expensive deep copies when passing objects into functions:
   ```cpp
   void printCar(const Car& c); // Fast, does not duplicate the object
   ```
2. **Mark Read-Only Methods as `const`**:
   If a method does not modify any attribute, append `const`:
   ```cpp
   int getAge() const { return age; }
   ```
3. **Always Declare Virtual Destructors in Base Classes**:
   If a class has at least one virtual function, its destructor must also be virtual:
   ```cpp
   virtual ~BaseClass() {}
   ```
   This ensures deleting a child object via a base pointer cleans up child resources properly without memory leaks.

---

## 7. How to Compile and Run

To compile and run any of these examples on Linux:

```bash
# Compile with C++17 standard
g++ -std=c++17 idooop.cpp -o app

# Run the executable
./app
```

---

## 8. Hands-on Practice Exercises by Section

Test your understanding after reading each section by solving these exercises in [letstrycppandopp.cpp](file:///home/datle/Documents/OOP/letstrycppandopp.cpp) or [idooop.cpp](file:///home/datle/Documents/OOP/idooop.cpp).

---

### Exercise 1: Classes and Objects (Book Catalog)
**Topic:** Section 2 - Basic Class & Object Syntax

#### 🎯 Problem Statement
Create a `Book` class representing a book in a library.

#### 📋 Requirements
1. **Attributes** (public):
   - `std::string title`
   - `std::string author`
   - `int pages`
2. **Methods**:
   - `void describe() const`: Prints `"[Title]" by [Author] ([Pages] pages)`
   - `bool isLong() const`: Returns `true` if `pages > 300`, otherwise `false`
3. In `main()`, instantiate two books:
   - Book 1: `"Atomic Habits"`, `"James Clear"`, `320` pages
   - Book 2: `"The Little Prince"`, `"Antoine de Saint-Exupery"`, `96` pages
   - Call `describe()` and check `isLong()` for each.

#### 💻 Expected Output
```text
"Atomic Habits" by James Clear (320 pages) - Long read: Yes
"The Little Prince" by Antoine de Saint-Exupery (96 pages) - Long read: No
```

<details>
<summary>💡 Click to reveal Solution</summary>

```cpp
#include <iostream>
#include <string>

class Book {
public:
    std::string title;
    std::string author;
    int pages;

    void describe() const {
        std::cout << "\"" << title << "\" by " << author << " (" << pages << " pages)";
    }

    bool isLong() const {
        return pages > 300;
    }
};

int main() {
    Book b1;
    b1.title = "Atomic Habits";
    b1.author = "James Clear";
    b1.pages = 320;

    Book b2;
    b2.title = "The Little Prince";
    b2.author = "Antoine de Saint-Exupery";
    b2.pages = 96;

    b1.describe();
    std::cout << " - Long read: " << (b1.isLong() ? "Yes" : "No") << "\n";

    b2.describe();
    std::cout << " - Long read: " << (b2.isLong() ? "Yes" : "No") << "\n";

    return 0;
}
```
</details>

---

### Exercise 2: Access Specifiers (Bank Vault)
**Topic:** Section 3 - `public`, `protected`, and `private`

#### 🎯 Problem Statement
Create a secure bank vault system that demonstrates the boundary between public, protected, and private members.

#### 📋 Requirements
1. Class `Safe`:
   - `public`: `std::string owner` (anyone can see who owns the safe)
   - `protected`: `int safeCode` (only `Safe` and child classes can see/modify the code)
   - `private`: `double storedCash` (strictly private to `Safe`)
   - Constructor to initialize all three fields.
   - Public method `void deposit(double amount)`: adds cash if positive.
   - Public method `double getCash() const`: returns the cash balance.
2. Derived Class `MasterSafe : public Safe`:
   - Inherits from `Safe`.
   - Method `void changeCode(int newCode)`: Changes `safeCode` and logs confirmation (works because `safeCode` is `protected`).
3. In `main()`:
   - Create a `MasterSafe`.
   - Print `owner` directly (public).
   - Try to change `safeCode` using `changeCode()` (method in child).
   - Deposit cash and check cash using the public methods.
   - Add commented-out lines showing what would trigger compiler errors if accessed directly.

#### 💻 Expected Output
```text
Owner: Alice
Safe code updated successfully!
Successfully deposited $500
Total cash in safe: $1500
```

<details>
<summary>💡 Click to reveal Solution</summary>

```cpp
#include <iostream>
#include <string>

class Safe {
public:
    std::string owner;

protected:
    int safeCode;

private:
    double storedCash;

public:
    Safe(std::string o, int code, double cash)
        : owner(o), safeCode(code), storedCash(cash) {}

    void deposit(double amount) {
        if (amount > 0) {
            storedCash += amount;
            std::cout << "Successfully deposited $" << amount << "\n";
        }
    }

    double getCash() const {
        return storedCash;
    }
};

class MasterSafe : public Safe {
public:
    MasterSafe(std::string o, int code, double cash)
        : Safe(o, code, cash) {}

    void changeCode(int newCode) {
        // ALLOWED: safeCode is protected in Safe
        safeCode = newCode;
        std::cout << "Safe code updated successfully!\n";

        // ERROR if uncommented:
        // storedCash = 0; // 'storedCash' is private to Safe!
    }
};

int main() {
    MasterSafe vault("Alice", 1234, 1000.0);

    // 1. PUBLIC:
    std::cout << "Owner: " << vault.owner << "\n";

    // 2. PROTECTED:
    // vault.safeCode = 9999; // ERROR: protected!
    vault.changeCode(9999);   // OK: child class modifies protected variable

    // 3. PRIVATE:
    // vault.storedCash = 0; // ERROR: private!
    vault.deposit(500.0);
    std::cout << "Total cash in safe: $" << vault.getCash() << "\n";

    return 0;
}
```
</details>

---

### Exercise 3: Constructors & Destructors (Hero Lifecycle)
**Topic:** Section 4 - Parameterized, Default Constructors & Destructors

#### 🎯 Problem Statement
Observe how objects are constructed and destroyed in memory using custom messages.

#### 📋 Requirements
1. Class `Hero`:
   - `std::string name`
   - `int hp`
2. **Parameterized Constructor**: Accepts `name` and `hp`, sets them using an initializer list, and prints:
   `"⚔️ Hero [name] enters the battle with [hp] HP!"`
3. **Default Constructor**: Sets name to `"Nameless Wanderer"` and hp to `100`, printing the same entry message.
4. **Destructor**: Prints `"💀 Hero [name] has fallen!"`
5. In `main()`:
   - Create a hero `Hero h1("Arthur", 150);`.
   - Open a nested block `{ ... }` and create `Hero h2("Lancelot", 120);` and `Hero h3;`.
   - Observe when `h2` and `h3` are destroyed compared to `h1`!

#### 💻 Expected Output
```text
⚔️ Hero Arthur enters the battle with 150 HP!
--- Entering dungeon block ---
⚔️ Hero Lancelot enters the battle with 120 HP!
⚔️ Hero Nameless Wanderer enters the battle with 100 HP!
--- Leaving dungeon block ---
💀 Hero Nameless Wanderer has fallen!
💀 Hero Lancelot has fallen!
--- Exiting main ---
💀 Hero Arthur has fallen!
```

<details>
<summary>💡 Click to reveal Solution</summary>

```cpp
#include <iostream>
#include <string>

class Hero {
private:
    std::string name;
    int hp;

public:
    Hero(std::string hName, int hHp) : name(hName), hp(hHp) {
        std::cout << "⚔️ Hero " << name << " enters the battle with " << hp << " HP!\n";
    }

    Hero() : name("Nameless Wanderer"), hp(100) {
        std::cout << "⚔️ Hero " << name << " enters the battle with " << hp << " HP!\n";
    }

    ~Hero() {
        std::cout << "💀 Hero " << name << " has fallen!\n";
    }
};

int main() {
    Hero h1("Arthur", 150);

    std::cout << "--- Entering dungeon block ---\n";
    {
        Hero h2("Lancelot", 120);
        Hero h3; // Default constructor
    }
    std::cout << "--- Leaving dungeon block ---\n";

    std::cout << "--- Exiting main ---\n";
    return 0;
}
```
</details>

---

### Exercise 4: Encapsulation (Smart Thermostat)
**Topic:** Section 5.1 - Data Hiding & Validation Invariants

#### 🎯 Problem Statement
Build a `Thermostat` class that stores temperature in Celsius internally, but ensures it can never be set below **Absolute Zero** (`-273.15 °C`).

#### 📋 Requirements
1. `private: double celsius;`
2. Constructor accepting `initialCelsius`. If valid, assign it; if invalid, default to `20.0`.
3. Setter `bool setCelsius(double c)`:
   - If `c >= -273.15`, update `celsius` and return `true`.
   - If `c < -273.15`, reject the change, print an error message, and return `false`.
4. Getters:
   - `double getCelsius() const`
   - `double getFahrenheit() const`: Formula: `celsius * 9.0 / 5.0 + 32.0`
   - `double getKelvin() const`: Formula: `celsius + 273.15`

#### 💻 Expected Output
```text
Setting temp to 25 C...
Celsius: 25 C | Fahrenheit: 77 F | Kelvin: 298.15 K
Setting temp to -300 C...
Error: Temperature cannot be below absolute zero (-273.15 C)!
Current temp remains: 25 C
```

<details>
<summary>💡 Click to reveal Solution</summary>

```cpp
#include <iostream>

class Thermostat {
private:
    double celsius;

public:
    Thermostat(double initialC) {
        if (initialC >= -273.15) {
            celsius = initialC;
        } else {
            std::cout << "Invalid initial temp! Defaulting to 20 C.\n";
            celsius = 20.0;
        }
    }

    bool setCelsius(double c) {
        if (c >= -273.15) {
            celsius = c;
            return true;
        }
        std::cout << "Error: Temperature cannot be below absolute zero (-273.15 C)!\n";
        return false;
    }

    double getCelsius() const { return celsius; }
    double getFahrenheit() const { return celsius * 9.0 / 5.0 + 32.0; }
    double getKelvin() const { return celsius + 273.15; }
};

int main() {
    Thermostat t(20.0);

    std::cout << "Setting temp to 25 C...\n";
    t.setCelsius(25.0);
    std::cout << "Celsius: " << t.getCelsius() << " C | "
              << "Fahrenheit: " << t.getFahrenheit() << " F | "
              << "Kelvin: " << t.getKelvin() << " K\n";

    std::cout << "Setting temp to -300 C...\n";
    t.setCelsius(-300.0);
    std::cout << "Current temp remains: " << t.getCelsius() << " C\n";

    return 0;
}
```
</details>

---

### Exercise 5: Inheritance (Electric Vehicle)
**Topic:** Section 5.2 - Base & Derived Classes, Constructor Chaining

#### 🎯 Problem Statement
Create a `Vehicle` base class and derive an `ElectricCar` class that adds battery management.

#### 📋 Requirements
1. Base Class `Vehicle`:
   - `protected: std::string brand; int speed;`
   - Constructor `Vehicle(std::string b, int s)`
   - Method `void accelerate(int amount)`: Increases speed.
2. Derived Class `ElectricCar : public Vehicle`:
   - `private: int batteryLevel;` (0 to 100%)
   - Constructor `ElectricCar(std::string b, int s, int battery)` that delegates `b` and `s` to `Vehicle` constructor.
   - Method `void charge(int percent)`: Increases `batteryLevel` up to a maximum of 100%.
   - Method `void showStatus() const`: Displays brand, current speed, and battery percentage.

#### 💻 Expected Output
```text
⚡ Tesla | Speed: 0 km/h | Battery: 60%
Accelerating...
Tesla speed is now 45 km/h.
Charging 30%...
Tesla battery is now 90%.
⚡ Tesla | Speed: 45 km/h | Battery: 90%
```

<details>
<summary>💡 Click to reveal Solution</summary>

```cpp
#include <iostream>
#include <string>
#include <algorithm>

class Vehicle {
protected:
    std::string brand;
    int speed;

public:
    Vehicle(std::string b, int s) : brand(b), speed(s) {}

    void accelerate(int amount) {
        speed += amount;
        std::cout << brand << " speed is now " << speed << " km/h.\n";
    }
};

class ElectricCar : public Vehicle {
private:
    int batteryLevel;

public:
    ElectricCar(std::string b, int s, int battery)
        : Vehicle(b, s), batteryLevel(battery) {}

    void charge(int percent) {
        batteryLevel = std::min(100, batteryLevel + percent);
        std::cout << brand << " battery is now " << batteryLevel << "%.\n";
    }

    void showStatus() const {
        std::cout << "⚡ " << brand << " | Speed: " << speed
                  << " km/h | Battery: " << batteryLevel << "%\n";
    }
};

int main() {
    ElectricCar car("Tesla", 0, 60);
    car.showStatus();

    std::cout << "Accelerating...\n";
    car.accelerate(45);

    std::cout << "Charging 30%...\n";
    car.charge(30);

    car.showStatus();
    return 0;
}
```
</details>

---

### Exercise 6: Polymorphism (RPG Combat Squad)
**Topic:** Section 5.3 - `virtual`, `override`, Base Pointers

#### 🎯 Problem Statement
Implement a combat party where different character classes execute unique attacks through a single base pointer loop.

#### 📋 Requirements
1. Base Class `Character`:
   - `protected: std::string name;`
   - Virtual destructor `virtual ~Character() {}`
   - Virtual function `virtual void attack() const`
2. Derived Classes:
   - `Warrior : public Character`: Overrides `attack()` -> `"⚔️ [name] swings a colossal Battle Axe!"`
   - `Mage : public Character`: Overrides `attack()` -> `"🔥 [name] launches a Meteor Strike!"`
   - `Ranger : public Character`: Overrides `attack()` -> `"🏹 [name] fires a Volley of Poison Arrows!"`
3. In `main()`:
   - Create a `std::vector<Character*>` holding a `Warrior`, a `Mage`, and a `Ranger`.
   - Loop over the squad and trigger each hero's `attack()`.
   - Clean up dynamically allocated memory with `delete`.

#### 💻 Expected Output
```text
⚔️ Conan swings a colossal Battle Axe!
🔥 Gandalf launches a Meteor Strike!
🏹 Legolas fires a Volley of Poison Arrows!
```

<details>
<summary>💡 Click to reveal Solution</summary>

```cpp
#include <iostream>
#include <vector>
#include <string>

class Character {
protected:
    std::string name;

public:
    Character(std::string n) : name(n) {}
    virtual ~Character() {}

    virtual void attack() const {
        std::cout << name << " attacks normally.\n";
    }
};

class Warrior : public Character {
public:
    Warrior(std::string n) : Character(n) {}
    void attack() const override {
        std::cout << "⚔️ " << name << " swings a colossal Battle Axe!\n";
    }
};

class Mage : public Character {
public:
    Mage(std::string n) : Character(n) {}
    void attack() const override {
        std::cout << "🔥 " << name << " launches a Meteor Strike!\n";
    }
};

class Ranger : public Character {
public:
    Ranger(std::string n) : Character(n) {}
    void attack() const override {
        std::cout << "🏹 " << name << " fires a Volley of Poison Arrows!\n";
    }
};

int main() {
    std::vector<Character*> squad;
    squad.push_back(new Warrior("Conan"));
    squad.push_back(new Mage("Gandalf"));
    squad.push_back(new Ranger("Legolas"));

    for (Character* hero : squad) {
        hero->attack();
    }

    // Free memory
    for (Character* hero : squad) {
        delete hero;
    }

    return 0;
}
```
</details>

---

### Exercise 7: Abstraction (Notification Gateway)
**Topic:** Section 5.4 - Pure Virtual Functions (`= 0`) & Interfaces

#### 🎯 Problem Statement
Design an extensible notification service where high-level alert functions do not depend on how messages are delivered.

#### 📋 Requirements
1. Pure Abstract Class / Interface `NotificationSender`:
   - `virtual ~NotificationSender() {}`
   - Pure virtual method `virtual void send(const std::string& recipient, const std::string& message) = 0;`
2. Concrete Classes implementing the interface:
   - `EmailSender`: Prints `"[EMAIL to recipient]: message"`
   - `PushSender`: Prints `"[PUSH NOTIFICATION to recipient]: message"`
3. Standalone Service Function:
   - `void sendSecurityAlert(NotificationSender& sender, const std::string& user)`
   - Dispatches `"Suspicious login detected on your account!"` to `user` via the passed sender.

#### 💻 Expected Output
```text
[EMAIL to user@example.com]: Suspicious login detected on your account!
[PUSH NOTIFICATION to UserDevice_881]: Suspicious login detected on your account!
```

<details>
<summary>💡 Click to reveal Solution</summary>

```cpp
#include <iostream>
#include <string>

// Pure Abstract Interface
class NotificationSender {
public:
    virtual ~NotificationSender() {}
    virtual void send(const std::string& recipient, const std::string& message) = 0;
};

class EmailSender : public NotificationSender {
public:
    void send(const std::string& recipient, const std::string& message) override {
        std::cout << "[EMAIL to " << recipient << "]: " << message << "\n";
    }
};

class PushSender : public NotificationSender {
public:
    void send(const std::string& recipient, const std::string& message) override {
        std::cout << "[PUSH NOTIFICATION to " << recipient << "]: " << message << "\n";
    }
};

// High-level module depends only on the abstraction
void sendSecurityAlert(NotificationSender& sender, const std::string& user) {
    sender.send(user, "Suspicious login detected on your account!");
}

int main() {
    EmailSender email;
    PushSender push;

    sendSecurityAlert(email, "user@example.com");
    sendSecurityAlert(push, "UserDevice_881");

    return 0;
}
```
</details>

---

### Capstone Challenge: Mini Inventory System
**Topic:** Combining All 4 Pillars

#### 🎯 Problem Statement
Build an object-oriented store inventory system that manages different product types.

#### 📋 System Specifications
1. **Abstraction**:
   - Abstract base class `Item`:
     - `protected: std::string name; double price;`
     - Pure virtual function: `virtual void printDetails() const = 0;`
     - Getter: `double getPrice() const { return price; }`
     - Virtual destructor `virtual ~Item() {}`
2. **Inheritance & Polymorphism**:
   - Derived class `BookItem : public Item`:
     - Has extra attribute `author` (string).
     - Overrides `printDetails()` to show: `Book: [name] by [author] | $[price]`
   - Derived class `ElectronicItem : public Item`:
     - Has extra attribute `warrantyMonths` (int).
     - Overrides `printDetails()` to show: `Electronic: [name] (Warranty: [months] mos) | $[price]`
3. **Encapsulation & Management**:
   - Class `Inventory`:
     - Holds a `std::vector<Item*> items;`
     - `void addItem(Item* item)`
     - `void printAll() const`
     - `double calculateTotalValue() const`
     - Destructor `~Inventory()` that automatically deletes all stored item pointers.

#### 💻 Expected Output
```text
=== Store Inventory ===
Book: The C++ Programming Language by Bjarne Stroustrup | $59.99
Electronic: Mechanical Keyboard (Warranty: 24 mos) | $120
Electronic: Wireless Mouse (Warranty: 12 mos) | $45.5
=======================
Total Inventory Value: $225.49
```

<details>
<summary>💡 Click to reveal Solution</summary>

```cpp
#include <iostream>
#include <vector>
#include <string>

// 1. ABSTRACTION
class Item {
protected:
    std::string name;
    double price;

public:
    Item(std::string n, double p) : name(n), price(p) {}
    virtual ~Item() {}

    virtual void printDetails() const = 0; // Pure virtual
    double getPrice() const { return price; }
};

// 2. INHERITANCE & POLYMORPHISM
class BookItem : public Item {
private:
    std::string author;

public:
    BookItem(std::string n, std::string a, double p)
        : Item(n, p), author(a) {}

    void printDetails() const override {
        std::cout << "Book: " << name << " by " << author << " | $" << price << "\n";
    }
};

class ElectronicItem : public Item {
private:
    int warrantyMonths;

public:
    ElectronicItem(std::string n, int w, double p)
        : Item(n, p), warrantyMonths(w) {}

    void printDetails() const override {
        std::cout << "Electronic: " << name << " (Warranty: " << warrantyMonths
                  << " mos) | $" << price << "\n";
    }
};

// 3. ENCAPSULATION & RESOURCE MANAGEMENT
class Inventory {
private:
    std::vector<Item*> items;

public:
    ~Inventory() {
        for (Item* item : items) {
            delete item;
        }
    }

    void addItem(Item* item) {
        items.push_back(item);
    }

    void printAll() const {
        std::cout << "=== Store Inventory ===\n";
        for (const Item* item : items) {
            item->printDetails();
        }
        std::cout << "=======================\n";
    }

    double calculateTotalValue() const {
        double total = 0.0;
        for (const Item* item : items) {
            total += item->getPrice();
        }
        return total;
    }
};

int main() {
    Inventory store;
    store.addItem(new BookItem("The C++ Programming Language", "Bjarne Stroustrup", 59.99));
    store.addItem(new ElectronicItem("Mechanical Keyboard", 24, 120.00));
    store.addItem(new ElectronicItem("Wireless Mouse", 12, 45.50));

    store.printAll();
    std::cout << "Total Inventory Value: $" << store.calculateTotalValue() << "\n";

    return 0; // store destructor cleans up all dynamic memory safely!
}
```
</details>

---

## 9. University Exam-Style Challenges (Requirements Only)

> [!IMPORTANT]
> **No Structural Hints Given.**
> You must analyze the real-world scenarios and mathematical/business requirements yourself. You are solely responsible for designing the class architecture: deciding which classes to declare, designing the inheritance hierarchy, selecting access specifiers (`public`, `private`, `protected`), choosing where `virtual` functions and destructors belong, and implementing the required algorithms and operator overloads.

---

### Challenge 1: Complex Number Arithmetic (`SoPhuc`) with Operator Overloading
*(Source: Final Exam UIT, Question 2)*

#### 🎯 Mathematical Background
A complex number can be expressed in two interchangeable forms:
1. **Cartesian form**: $z = a + bi$
   - $a$: real component
   - $b$: imaginary component
2. **Polar coordinate form**: $z = r e^{i\phi}$
   - Modulus: $r = \sqrt{a^2 + b^2}$
   - Argument: $\phi = \arctan(b / a)$ (when $a \ne 0$)
   - Edge cases for $\phi$:
     - If $a = 0$ and $b > 0$: $\phi = \frac{\pi}{2}$
     - If $a = 0$ and $b < 0$: $\phi = -\frac{\pi}{2}$ (or $\frac{3\pi}{2}$)
     - If $a = 0$ and $b = 0$: $\phi = 0$

#### Operations to Support
1. **Multiplication of two complex numbers**:
   $$(a_1 + b_1 i)(a_2 + b_2 i) = (a_1 a_2 - b_1 b_2) + (a_1 b_2 + a_2 b_1)i$$
2. **Exponentiation to integer power $n \ge 0$ (De Moivre's Theorem)**:
   $$z^n = (r e^{i\phi})^n = r^n e^{i(n\phi)} = r^n \cos(n\phi) + i \cdot r^n \sin(n\phi)$$

#### 📋 Exact Requirement
Implement the `SoPhuc` class definition and necessary overloaded operators so that the following test `main()` runs correctly:

```cpp
#include <iostream>

int main() {
    SoPhuc c1;             // Default: a = 0, b = 0
    SoPhuc c2(1, 1);       // a = 1, b = 1

    SoPhuc c3 = c1 * c2;   // Overloaded multiplication operator
    SoPhuc c4 = (c2) ^ 10; // Overloaded exponentiation operator

    // Output formatted complex number (e.g. "a + bi")
    std::cout << "c2 = " << c2 << "\n";
    std::cout << "c3 = c1 * c2 = " << c3 << "\n";
    std::cout << "c4 = (c2)^10  = " << c4 << "\n";

    return 0;
}
```

---

### Challenge 2: Cultivator & Combat Skill Hierarchy System (`Tu Si & Ky Nang`)
*(Source: Final Exam UIT, Question 3)*

#### 🎯 World Setting
In the year 2050, after massive cosmic shifts, Earth enters an era of Spiritual Awakening (*Linh Khí Khôi Phục*). Humans who cultivate spiritual energy are known as Cultivators (*Tu Sĩ*).

#### 📋 System Specifications

##### 1. Tu Sĩ (Cultivator)
- Each Cultivator has:
  - Full Name (*Họ tên*)
  - Realm (*Cảnh giới tu luyện*)
  - Maximum Mana Points (*Linh lực tối đa - MP*)
  - A list of learned skills (*Danh sách kỹ năng đã học*)
- The cultivation realms on Earth have specific limits:
  | Realm (*Cảnh giới*) | Description | Skill Capacity Limit | Maximum Mana Points (MP) |
  | :--- | :--- | :---: | :---: |
  | **Trúc Cơ** | Foundation stage; absorbs mana to refine physical flesh | $1 \le k \le 3$ skills | Random in $[1, 100]$ |
  | **Kết Đan** | Condenses a core inside the dantian | $2 \le k \le 5$ skills | Random in $[100, 300]$ |
  | **Nguyên Anh** | Core shatters into a spiritual soul infant | $3 \le k \le 7$ skills | Random in $[300, 700]$ |

*(Note: Assume a helper function `rand(x, y)` exists or use `<random>` to generate integers in $[x, y]$).*

##### 2. Kỹ Năng (Skill Hierarchy)
- **Common Skill Properties**:
  - Skill Name (*Tên kỹ năng*)
  - Skill Description / Information (*Thông tin kỹ năng*)
  - Skill Level ($SL$)
  - Cast Time ($CT$ - measured in seconds)
  - Base Damage ($BD$)
  - **Final Damage ($FD$)**:
    $$FD = BD \times SL$$
- **Skill Types**:
  1. **Kỹ năng Thông Thường (Physical / Weapon Skill)**:
     - Directly relies on physical combat or physical weapons (sword, blade, bow).
     - Does **NOT** consume mana ($MP = 0$).
     - Has **NO** cooldown ($CD = 0$). Can be cast consecutively without waiting.
     - Cast time ($CT$) is very brief: strictly $0 < CT \le 1$ second.
  2. **Kỹ năng Ma Pháp (Spiritual / Magic Spell)**:
     - Uses spiritual energy to invoke massive spell attacks.
     - Has a Cast Time ($CT \ge 1$ second) during which the caster chants.
     - Consumes Mana ($MP > 0$).
     - Has a Cooldown ($CD > 0$ seconds). Once used, it enters a recovery period and cannot be cast again until the cooldown elapses.
- **Damage Per Second (DPS) Formula**:
  $$DPS = \frac{FD}{CT + CD}$$

##### Example Skill Table for Verification:
| Attribute | Lưu Quang Kiếm | Hỏa Cầu Thuật |
| :--- | :--- | :--- |
| **Loại kỹ năng** | Thông thường | Ma pháp |
| **Cấp kỹ năng ($SL$)** | 7 | 5 |
| **Thời gian thi triển ($CT$)** | 0.5 giây | 2 giây |
| **Linh lực tiêu hao ($MP$)** | Không có ($0$) | 50 |
| **Thời gian hồi chiêu ($CD$)** | Không có ($0$) | 3 giây |
| **Sát thương cơ bản ($BD$)** | 40 | 100 |
| **Sát thương cuối ($FD$)** | $7 \times 40 = 280$ | $5 \times 100 = 500$ |
| **DPS** | $\frac{280}{0.5 + 0} = 560$ | $\frac{500}{2 + 3} = 100$ |

#### 🛠️ Functional Requirements
Design the complete class hierarchy in C++ and implement a driver program to:
1. **Input and Output**: Enter all info for one Cultivator (Realm, generated MP, list of learned skills) and display their complete profile.
2. **Skill Detail & DPS Inspection**: Allow user to pick a skill by name or index from the list and calculate its DPS.
3. **Top DPS Ranking**: Find and display information of the **Top 2 highest DPS skills** belonging to the cultivator.
4. **Boss Battle Simulation**: Suppose a Monster Boss has $4000$ HP. Assuming infinite mana and continuous casting of the cultivator's highest-DPS skill, calculate exactly how many seconds it takes to slay the beast.

---

### Challenge 3: Resort Room Booking & Amenity Billing System

#### 🎯 Business Context
A luxury resort operates diverse accommodations. Each room category has distinct pricing algorithms, amenity bundles, and surcharge policies.

#### 📋 System Specifications

##### 1. Base Room Information
- Unique Room Identifier (e.g. `"R101"`)
- Guest Name
- Number of booked nights ($N \ge 1$)
- Base Nightly Rate ($B > 0$)

##### 2. Room Categories & Pricing Rules
1. **Standard Room**:
   - Total Cost $= N \times B$.
   - No extra surcharges or complimentary services.
2. **Deluxe Room**:
   - Includes complimentary gourmet breakfast for 2 guests.
   - Surcharge: A mandatory $15\%$ hospitality service fee added to the room cost:
     $$\text{Total Cost} = (N \times B) \times 1.15$$
3. **Presidential Suite**:
   - Includes 24/7 dedicated butler service (fixed surcharge of $\$200$ per stay).
   - Unlimited premium minibar service (additional $\$50$ per night).
   - Luxury government tax of $20\%$ applied on the entire pre-tax total:
     $$\text{Total Cost} = \Big((N \times B) + 200 + (50 \times N)\Big) \times 1.20$$

##### 3. Loyalty Promotion Rule
If a guest stays **more than 5 nights** ($N > 5$), they receive a $10\%$ discount off their final room bill.

#### 🛠️ Functional Requirements
Write an object-oriented system that:
1. Manages an arbitrary collection of booked rooms in memory.
2. Prints an itemized receipt for every room (showing guest name, room ID, room type, nights, base price, and total calculated bill after discounts).
3. Computes the **Total Revenue** generated by the entire resort.
4. Finds and displays the specific room that generated the **Highest Bill**.

---

### Challenge 4: Logistics Fleet & Highway Toll Checkpoint Dispatcher

#### 🎯 Business Context
A national highway toll station categorizes and charges vehicles based on gross weight, passenger capacity, axle configurations, and hazardous material manifests.

#### 📋 System Specifications

##### 1. Common Vehicle Data
- License Plate string
- Driver Full Name
- Curb / Tare Weight (empty vehicle weight in metric tons)

##### 2. Vehicle Classifications & Toll Fee Algorithms
1. **Sedan / Passenger Car (`Xe Con`)**:
   - Passenger seating capacity (e.g., 4 to 7 seats).
   - Flat Toll: $\$5.00$.
2. **Cargo Freight Truck (`Xe Tải`)**:
   - Carries Payload Cargo Weight (in metric tons).
   - Toll calculation:
     $$\text{Base Fee} = \$10.00 + (\$3.00 \times \text{Cargo Weight})$$
   - **Overload Penalty**: If the Gross Weight ($\text{Curb Weight} + \text{Cargo Weight}$) exceeds $20.0$ tons, an immediate safety violation penalty of $\$50.00$ is added.
3. **Intermodal Container Carrier (`Xe Container`)**:
   - Trailer Size: either `20` ft or `40` ft.
     - 20 ft trailer base toll: $\$30.00$
     - 40 ft trailer base toll: $\$50.00$
   - Hazardous Material Flag (`bool isHazardous`): If the container is carrying flammable or toxic chemicals, a mandatory $30\%$ hazardous transport surcharge is added to the base toll.

#### 🛠️ Functional Requirements
Write an object-oriented system that:
1. Accepts a mixed convoy of vehicles entering the toll checkpoint.
2. Calculates the total toll revenue collected from the convoy.
3. Identifies and prints a report of all vehicles flagged for safety violations (overloaded trucks) or special security protocols (hazardous containers).
4. Prints an audit log of all vehicles sorted by their final toll fee from highest to lowest.
