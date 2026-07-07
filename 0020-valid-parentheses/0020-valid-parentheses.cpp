class Solution {
public:
    bool isValid(string s) {
        
        stack<char> ch;
        int i = 0;
        while(i<s.size()){
           if( s[i]== '(' || s[i] == '[' || s[i]=='{'){
              ch.push(s[i]);
           }
           else{
              if(ch.empty()) return false;
           if((s[i] == ')' && ch.top() == '(')||(s[i] == ']' && ch.top() == '[')||(s[i] == '}' && ch.top() == '{')){
              ch.pop();
           }
           else return false;
           }
           i++;
        }
        if(ch.empty() == true) return true;
        else return false;
    }
};