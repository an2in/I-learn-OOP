#include <iostream>
#include <string>
using namespace std;
class Book {
public:
  // Attributes / data
  string title;
  string author;
  int pages;

  // Method/ Function
  void describe() const {
    cout << "\"" << title << "\"" << " by " << author << " (" << pages
         << " pages)";
  }
  bool isLong() const {
    if (pages > 300)
      return true;
    else
      return false;
  }

  void LongRead() {
    if (isLong())
      cout << "- Long read: Yes";
    else
      cout << "- Long read: No";
  }
};
int main() {
  Book B1, B2;
  // Book 1
  B1.title = "Atomic Habits";
  B1.pages = 320;
  B1.author = "James Clear";

  // Book 2
  B2.title = "The Little Prince";
  B2.author = "Antoine de Saint-Exupery";
  B2.pages = 96;

  B1.describe();
  B1.LongRead();
  cout << "\n";
  B2.describe();
  B2.LongRead();
  return 0;
}