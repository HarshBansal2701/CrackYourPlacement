class Solution {
public:
    int strStr(string haystack, string needle) {
        // Approach -1 Using in-build find function
        // if(haystack.find(needle) != string::npos){
        //     return haystack.find(needle);
        // }
        // return -1;
        // TC -> O(n);


        // Approach-2 Without using any function
        int h = haystack.size();
        int n = needle.size();

        if(h<n){
            return -1;
        }

        int j = 0;

        for(int i = 0 ; i<h-n+1 ; i++){
            if(haystack[i] == needle[j]){
                int x = i;
                while(j<n && haystack[x]==needle[j]){
                    x++;
                    j++;
                }
            }
            if(j==n){
                    return i;
            }
            j=0;
        }
        return -1;
        // TC -> O(h*n)
    }
};