class Solution {

    bool checkpalindrom(string s, int i,int j){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int x = 1;

        int i = 0; 
        int j=s.size()-1;

        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
                
                bool ans1 = checkpalindrom(s,i+1,j);
                bool ans2 = checkpalindrom(s,i,j-1);

                return ans1 || ans2;
            }
        }
        return true;
    }
};