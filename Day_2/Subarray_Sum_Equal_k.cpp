class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Approach
        // Similar pattern to Subarray sum divisible by k 
        unordered_map<int,int> mp;
        int ans = 0;
        mp[0] = 1;
        int sum = 0;
        for(int i = 0 ; i<nums.size(); i++){
            sum += nums[i];
            int rem = sum-k;
            if(mp.contains(rem)){
                ans += mp[rem];
            }
            mp[sum]++;
        }
        return ans;

        // TC -> O(n) , SC -> O(1)
    }
};