class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Method-1 (Find the frequescy of each element)

        // unordered_map<int,int> mp;
        // for(int i = 0 ; i<nums.size(); i++){
        //     mp[nums[i]]++;
        // }
        // for(auto it:mp){
        //     if(it.second > nums.size()/2){
        //         return it.first;
        //     }
        // }
        // return -1;
        // TC-> O(n) , SC-> O(n)

        // Method-2 (without using extra spacing)

        int ele = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); i++) {

            if (ele == nums[i]) {
                count++;
            } else {
                count--;
                if (count == 0) {
                    ele = nums[i];
                    count = 1;
                }
            }
        }
        return ele;
        // TC-> O(n) , SC -> O(1)
    }
};