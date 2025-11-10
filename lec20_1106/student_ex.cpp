#include <iostream>
using namespace std;

class Student {
  char name[80];
  unsigned long UIN;
  unsigned int year;
  float GPA;

public:
  Student(char const *name, unsigned int UIN, unsigned int year, float GPA);
  float get_GPA();
  char const *get_name();
};

Student::Student(char const *name, unsigned int UIN, unsigned int year,
                 float GPA) {
  strcpy(this->name, name);
  this->UIN = UIN;
  this->year = year < 0 ? 1 : year;
  this->GPA = GPA;
}

float Student::get_GPA() { return this->GPA; }

char const *Student::get_name() { return this->name; }

int main(void) {
  Student s1 = Student("Garfield", 123456, 6, 3.5);
  cout << s1.get_name() << " is an excellent student!" << endl;
  cout << "Their GPA is: " << s1.get_GPA() << endl;
}
