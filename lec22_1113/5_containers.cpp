#include <iostream>
#include <iterator> // for iterators
#include <vector>   // for vectors

using namespace std;

int main() {
  vector<int> ar = {1, 2, 3, 4, 5};
  vector<char> cr = {'a', 'b', 'c', 'd', 'e'};
  vector<int> br = {10, 20, 30, 40, 50, 60, 70, 80};
  vector<int>::iterator ptr;      // Declaring iterator to a vector
                                  //
  ar.insert(ar.begin() + 2, 100); // Insert 100 at 3rd position
  ar.insert(ar.begin() + 5, 100); // Insert 100 at 5rd position
  cout << "The vector elements are : ";
  for (ptr = ar.begin(); ptr < ar.end(); ptr++)
    cout << *ptr << " " << endl;

  return 0;
}
