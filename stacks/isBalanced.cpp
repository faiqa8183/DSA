#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalanced(string str) {
  stack<char> s;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
      s.push(str[i]);
    } else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
      if (s.empty()) {
        return false;
      } else if ((str[i] == ')' && s.top() == '(') ||
                 (str[i] == ']' && s.top() == '[') ||
                 (str[i] == '}' && s.top() == '{')) {
        s.pop();
      } else {
        return false;
      }
    }
  }
  return s.empty();
}

int main() {
  string str1 = "{()}[]"; // balanced
  string str2 = "{()[]{}}"; // balanced
  string str3 = "{(})"; // not balanced
  string str4 = "("; // not balanced
  string str5 = "((())"; // not balanced
  cout << str1 << " is " << (isBalanced(str1) ? "balanced" : "not balanced") << endl;
  cout << str2 << " is " << (isBalanced(str2) ? "balanced" : "not balanced") << endl;
  cout << str3 << " is " << (isBalanced(str3) ? "balanced" : "not balanced") << endl;
  cout << str4 << " is " << (isBalanced(str4) ? "balanced" : "not balanced") << endl;
  cout << str5 << " is " << (isBalanced(str5) ? "balanced" : "not balanced") << endl;
  return 0;
}

