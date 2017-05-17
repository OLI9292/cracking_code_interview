// given two strings, write a method to decide if one is a permutation of another

#include <iostream>
using namespace std;

bool are_permutations(string str1, string str2);

bool are_permutations(string str1, string str2) {
  std::sort(str1.begin(), str1.end());
  std::sort(str2.begin(), str2.end());
  return (str1 == str2);
}

int main() {

  std::cout << are_permutations("lleho", "heelo") << std::endl;
  std::cout << are_permutations("olehe", "heelo") << std::endl;

  return 0;
}