#include <iostream>

/*Example of a pointer to a function that takes two integers as parameters and
 * returns their sum.*/

int add(int a, int b) { return a + b; }

int main() {
  // Declare a pointer to a function that takes two integers and returns an
  // integer
  int (*funcPtr)(int, int);

  // Assign the address of the 'add' function to the function pointer
  funcPtr = &add;

  // Call the function using the function pointer
  int result = funcPtr(5, 10);

  std::cout << "The sum is: " << result << std::endl; // Output: The sum is: 15

  return 0;
}
