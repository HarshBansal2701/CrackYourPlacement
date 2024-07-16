class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // // Method-1 (Brute Force)
        // int count = 0;

        // for(int i = 0 ; i<nums.size(); i++){
        //     int temp = 0;
        //     for(int j = i ; j<nums.size(); j++){
        //         temp += nums[j];
        //         if(temp%k == 0){
        //             count++;
        //         }
        //     }
        // }
        // return count;
        // // Method-1 => TC - O(n)


        // Method-2 (Using Modulo operator)
        // maintain running sum of elements and use modulo to find its reminder
        // use hashmap to count freq of each reminder
        // it same reminer appears again i.e.sum of elements b/w these subarrays is divisible ny k

        int count = 0;
        int sum=0;
        unordered_map<int,int> mp;
        mp[0] = 1;

        for(int i=0 ; i<nums.size(); i++){
            sum += nums[i];
            int rem = sum%k;

            if(rem<0){
                rem+=k;
            }
            if(mp.contains(rem)){
                count += mp[rem];
            }
            mp[rem]++;
        }
        return count;

        // Method-2 => TC- O(n)
    }
};