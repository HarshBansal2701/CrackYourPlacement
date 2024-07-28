class Solution {
public:
    int climbStairs(int n) {
        if(n==2 || n==1){
            return n;
        }

        int curr = 2;
        int prev = 1;

        for(int i = 3 ; i<=n ; i++){
            int temp = curr + prev;
            prev = curr;
            curr = temp;
        }

        return curr;
    }
};