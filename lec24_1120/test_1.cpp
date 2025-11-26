#include <iostream>
using namespace std;

struct Person {
  string name;
  int age;

  Person(string n, int a) : name(n), age(a) {};
};

void say_age(Person p) {
  cout << "I am " << p.name << endl;
  cout << "I am " << p.age << " years old." << endl;
}

int main(void) {
  Person p("Alice", 30);
  cout << "Person created." << endl;
  say_age(p);
  return 0;
}
