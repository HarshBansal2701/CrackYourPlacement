class Solution {
public:
    bool isValid(string s) {
        // Approach -> using Stack
        // when encounter open brackets push in stack
        // When encounter close brackets check it if not match then return false else pop top element 
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if ((s[i] == ')' || s[i] == ']' || s[i] == '}')) {
                if (!st.empty() && ((st.top() == '(' && s[i] == ')') ||
                    (st.top() == '{' && s[i] == '}') ||
                    (st.top() == '[' && s[i] == ']'))) {
                    st.pop();
                } else {
                    return false;
                }
            } else {
                st.push(s[i]);
            }
        }
        if (st.empty()) {
            return true;
        }
        return false;
        // TC-> O(n) , SC_> O(n)
    }
};