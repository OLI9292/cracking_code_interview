/*
A child is running up a staircase with n steps and can hop either 1 step, 2 steps, or 3 steps at a time.
Implement a method to count how many possible ways the child can run up the stairs.
*/

#include <iostream>

int stairs_permutations(int steps_count) {
  if (steps_count == 3) {
    return 4;
  } else if (steps_count == 2) {
    return 2;
  } else if (steps_count == 1) {
    return 1;
  }
  return stairs_permutations(steps_count - 3) + stairs_permutations(steps_count - 2) + stairs_permutations(steps_count - 1);
}

int main() {

  std::cout << stairs_permutations(5) << std::endl;

  return 0;
}
