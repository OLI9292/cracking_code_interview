// algorithm to determine if a string has all unique characters

#include <iostream>
#include <set>
using namespace std;

bool all_chars_unique(string str);

bool all_chars_unique(string str) {

  std::string line = "abcdefghijklmnopqrstuvwxyz0123456789";
  std::set<char> checker(str.begin(), str.end());

  return (checker.size() == str.size());
}

int main() {

  std::cout << all_chars_unique("helo") << endl;
  std::cout << all_chars_unique("helop") << endl;
  std::cout << all_chars_unique("helopp") << endl;
  std::cout << all_chars_unique("helopr") << endl;
  std::cout << all_chars_unique("heloopr") << endl;

  return 0;
}