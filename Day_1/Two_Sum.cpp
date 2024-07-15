class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // // Method-1 (Nested For Loop)
        // for(int i = 0 ; i<nums.size(); i++){
        //     for(int j = i+1 ; j<nums.size(); j++){
        //         if(nums[i]+nums[j]==target){
        //             return {i,j};
        //         }
        //     }
        // }
        // return {};
        // // Method1 => TC - O(n^2)


        // Method-2 (using Unordered_map)
        // if target-nums[i] already present in the map return their indexes
        // else update the map
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            if(mp.contains(target-nums[i])){
                return {mp[target-nums[i]], i};
            }
            mp[nums[i]] = i;
        }
        return {-1,-1};
        // Method-2 => TC - O(n) , SC - O(n)
    }
};