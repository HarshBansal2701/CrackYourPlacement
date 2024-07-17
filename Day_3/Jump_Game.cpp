class Solution {
public:
    bool canJump(vector<int>& nums) {
        // Method -> At every index update the value of max_jump from that index
        int jump = 0;
        for(int i = 0 ; i<nums.size(); i++){
            if(i> jump){
                return false;
            }
            jump = max(jump , i+nums[i]);
        }
        return true;

        // TC -> O(n) , SC -> O(1)
    }
};