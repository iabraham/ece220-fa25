#include <iostream>
using namespace std;

struct Person {
  string name;
  int age;

  Person(string n, int a) : name(n), age(a) {};

  /* Yes structs can have methods too! */

  void say_age() {
    cout << "I am " << this->name << endl;
    cout << "I am " << this->age << " years old." << endl;
  }
};

int main(void) {
  Person p("Alice", 30);
  cout << "Person created." << endl;
  p.say_age();
  return 0;
}
