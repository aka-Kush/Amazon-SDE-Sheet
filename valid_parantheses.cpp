// https://leetcode.com/problems/valid-parentheses/description/

/*
Logic:
    - Create a stack
    - Push any opening brackets to stack
    - Check if stack is empty and return
    - If next element is closing bracket, check if it has matching opening bracket on top of stack. If yes then pop the element otherwise return false
    - finally return if stack is empty or not
*/

#include <bits/stdc++.h>
using namespace std;
bool isMatching(char a, char b){
    if(
        a == '(' && b == ')' ||
        a == '{' && b == '}' ||
        a == '[' && b == ']'
    ) return true;
    else return false;
};
bool isParanthesesMatching(string s){
    stack<char> st;
    for(int i = 0; i < s.length(); i++){
        char cur = s.at(i);
        if(cur == '(' || cur == '[' || cur == '{'){
            st.push(cur);
        }
        else{
            if(st.empty()){
                return false;
            }
            if(!isMatching(st.top(), cur)){
                return false;
            }
            else{
                st.pop();
            }
        }
    }
    return st.empty();
};
int main()
{
    string s = "()[{}]";
    if(isParanthesesMatching(s)){
        cout << "True" << endl;
    }
    else cout << "False" << endl;
    return 0;
}
