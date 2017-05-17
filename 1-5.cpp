/*
There are three types of edits that can be performed on strings: insert a character, remove a character,
or replace a character.  Given two strings, write a function to check if they are one edit (or zero edits) away.
*/

#include <iostream>
#include <string>

using namespace std;

bool oneEditAway(string s1, string s2);
bool oneEditInsert(string s1, string s2);
bool oneEditReplace(string s1, string s2);


bool oneEditInsert(string s1, string s2) {
  int index1 = 0;
  int index2 = 0;
  
  while (index2 < s2.length() && index1 < s1.length()) {
    if (s1[index1] != s2[index2]) {
      if (index1 != index2) {
        return false;
      }
      index2++;
    } else {
      index1++;
      index2++;
    }
  }
  return true;
}

bool oneEditReplace(string s1, string s2) {
  int difference = 0;
  int index = 0;
  
  while (index < s2.length()) {
    if (s1[index] != s2[index]) {
      difference++;
      if (difference > 1) {
        return false;
      }
    }
    index++;
  }
  return true;
}


bool oneEditAway(string s1, string s2) {
  if (s1.size() + 1 == s2.size()) {
    return oneEditInsert(s1, s2);
  } else if (s1.size() == s2.size()) {
    return oneEditReplace(s1, s2);
  } else if (s1.size() - 1 == s2.size()) {
    return oneEditInsert(s2, s1);
  }
  return false;
}

int main() {

  cout << oneEditAway("ple", "pale") << endl;
  cout << oneEditAway("pales", "pale") << endl;
  cout << oneEditAway("pale", "bale") << endl;
  cout << oneEditAway("pale", "bake") << endl;

  return 0;
}
