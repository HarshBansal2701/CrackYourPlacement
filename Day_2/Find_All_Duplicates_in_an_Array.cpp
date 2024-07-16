class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // // Method-1 (Maintain a visited array)

        // vector<bool> visi(nums.size()+1, false);
        // vector<int> ans;

        // for(int i = 0 ; i<nums.size(); i++){
        //     if(visi[nums[i]]){
        //         ans.push_back(nums[i]);
        //     }
        //     else{
        //         visi[nums[i]] = true;
        //     }
        // }
        // return ans;
        // // Method-1 => TC- O(n) , SC - O(n)


        // Method-2 (playing with indexes)

        vector<int> ans;

        for(int i = 0 ; i<nums.size(); i++){
            if(nums[abs(nums[i])-1] < 0){
                ans.push_back(abs(nums[i]));
            }
            else{
                nums[abs(nums[i])-1] *= -1;
            }
        }
        return ans;
        // Method => TC- O(n) , SC - O(1)
    }
};