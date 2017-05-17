// given a string, write a function to check if it is a permutation of a palindrome

#include <iostream>
#include <unordered_map>

using namespace std;

bool is_palindrome_permutation(const char* p);

bool is_palindrome_permutation(const char* p) {
  
  unordered_map<char, size_t> m;

  while (*p) {
    if (isalpha(*p)) {
      m[*p]++;
      cout << m[*p].second << endl;
    }
    p++;
  }

  size_t count = 0;

  for (auto& p : m) {
    cout << p.second << endl;
    if (p.second % 2 == 1) {
      if (count++ == 2) {
        return false;
      }
    }
  }

  return true;
}

int main() {

  cout << is_palindrome_permutation("hio") << endl;
  cout << is_palindrome_permutation("hiih") << endl;
  cout << is_palindrome_permutation("hhiit") << endl;

  return 0;
}
