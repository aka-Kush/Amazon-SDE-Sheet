// https://leetcode.com/problems/valid-parentheses/description/
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