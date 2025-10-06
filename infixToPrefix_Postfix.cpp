#include <iostream>
#include <stack>
#include <algorithm>
#include <cctype>
using namespace std;

int prec(char op) {
    if (op == '^') return 3;
    else if (op == '*' || op == '/') return 2;
    else if (op == '+' || op == '-') return 1;
    else return -1;
}

bool isOperator(char c) {
     if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
     {
     	return true;
	 }else{
	 	return false;
	 }
	 	
}

string infixToPostfix(string exp) {
    stack<char> st;
    string result = "";

    for (char ch : exp) {
         if (isalnum(ch)) {
            result += ch;
        }
         else if (ch == '(') {
            st.push(ch);
        }
         else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop(); 
        }
         else if (isOperator(ch)) {
            while (!st.empty() && prec(st.top()) >= prec(ch)) {
                result += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

     while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}

 string infixToPrefix(string exp) {
     reverse(exp.begin(), exp.end());

     for (int i = 0; i < exp.length(); i++) {
        if (exp[i] == '(') exp[i] = ')';
        else if (exp[i] == ')') exp[i] = '(';
    }

     string postfix = infixToPostfix(exp);

     reverse(postfix.begin(), postfix.end());
    return postfix;
}

 int main() {
    string str;

    cout << "Enter infix expression: ";
    cin >> str;
	cout<<endl;
    cout << "Infix Expression: " << str<<endl;
    cout << "Postfix Expression: " << infixToPostfix(str)<<endl;;
    cout << "Prefix Expression: " << infixToPrefix(str) << endl;

    return 0;
}

