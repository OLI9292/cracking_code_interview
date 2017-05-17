/*
Implement a method to perform basic string compression using the counts 
of repeated characters. For example, the string aabcccccaaa would become
a2b1c5a3. If the "compressed" string would not become smaller than the
original string, your method should return the original string. You can
assume the string has only uppercase and lowercase letters (a-z).
*/

#include <iostream>
#include <string>

std::string compress(std::string str);

std::string compress(std::string str) {

  std::string compressed;
  char currentChar;
  int currentCharCount;

  for (int i = 0; i <= str.length(); i++) {
    if (str[i] == currentChar) {
      currentCharCount++;
    } else {    
      if (i != 0) {
        compressed += currentChar;
        compressed += std::to_string(currentCharCount);
      }
      currentChar = str[i];
      currentCharCount = 1;
    }
  }

  return (compressed.length() > str.length()) ? str : compressed;
}

int main() {

  std::cout << compress("hellllllllllobooddd") << std::endl;
  std::cout << compress("hippy") << std::endl;

  return 0;
}
