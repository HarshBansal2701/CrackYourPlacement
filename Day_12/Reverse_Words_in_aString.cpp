class Solution {
public:
    string reverseWords(string s) {
        // Using StringStream
        // string token = "";
        // stringstream ss(s);

        // string result = "";

        // while(ss >> token){
        //     result = token + " " + result; 
        // }
        // result.pop_back();

        // return result;

        // Approach-2
        reverse(s.begin(), s.end());

        int i = 0,l=0,r=0,n=s.size();

        while(i<n){
            while(i<n && s[i]!=' '){
                s[r++] = s[i++];
            }
            if(l<r){
                reverse(s.begin()+l , s.begin()+r);
                s[r] = ' ';
                r++;
                l = r;
            }
            i++;
        }

        s = s.substr(0,r-1);
        return s;
    }
};