#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string infixToPostfix(const string &expr) {
    stack<char> st;
    string postfix = "";

    for (char ch : expr) {
        if (isalnum(ch)) {
            postfix += ch;
            postfix += ' ';
        }
        else if (ch == '(') {
            st.push(ch);
        }
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                postfix += ' ';
                st.pop();
            }
            st.pop();
        }
        else { 
            while (!st.empty() && precedence(st.top()) >= precedence(ch)) {
                postfix += st.top();
                postfix += ' ';
                st.pop();
            }
            st.push(ch);
        }
    }

    while (!st.empty()) {
        postfix += st.top();
        postfix += ' ';
        st.pop();
    }

    return postfix;
}
void generateCode(const string &postfix) {
    stack<string> st;

    for (char ch : postfix) {
        if (isalnum(ch)) {
            cout << "PUSH " << ch << endl;
            st.push(string(1, ch));
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            string b = st.top(); st.pop();
            string a = st.top(); st.pop();
            if (ch == '+') cout << "ADD" << endl;
            if (ch == '-') cout << "SUB" << endl;
            if (ch == '*') cout << "MUL" << endl;
            if (ch == '/') cout << "DIV" << endl;
            st.push("T"); 
        }
    }
}

int main() {
    string expr = "(a+b)*c";
    string postfix = infixToPostfix(expr);

    cout << "Generated Stack Machine Code:\n";
    generateCode(postfix);

    return 0;
}
