class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans="";
        while(columnNumber>0){
            columnNumber--;
            char x = 'A'+(columnNumber%26);
            ans = x+ans;
            columnNumber /= 26;
        }
        return ans;
    }
};