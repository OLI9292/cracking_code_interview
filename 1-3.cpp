// replace all spaces in string with %20

#include <iostream>
#include <string>
using namespace std;

string spaces2percent20(string str);

string spaces2percent20(string str) { 
  size_t index;
  while((index = str.find(' ')) != string::npos)
    str = str.replace(index, 1, "%20");
  return str;
}

int main() {

  cout << spaces2percent20("hi  I  am Sam") << endl;

  return 0;
}
