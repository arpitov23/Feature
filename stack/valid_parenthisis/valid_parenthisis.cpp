#include <string>
#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;


bool isValid(string str) {

    std::stack<char> stack;
    unordered_map<char, char> bracket = { {')', '('},
    { '}', '{' },
        {']','['} };

    for (auto ch : str) {
        if (ch == '(' || ch == '{' || ch == '[') {
            stack.push(ch);

        }
        else if (bracket.find(ch) != bracket.end()) {
            if (stack.empty() || stack.top() != bracket[ch]) {
                return false;
            }
            stack.pop();
        }
    }
    return  stack.empty();
}
int main() {
    
    std::string s = "[";
    std::cout << std::boolalpha << isValid(s) << std::endl; // Output: true
    return 0;
}