class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Method -> Sorting and two pointer
        // Sort the array and start iterating over it 
        //  in each iteration set two pointer one at next of iterative index and other at end index
        // then apply similar approach as Two Sum
        sort(nums.begin(),nums.end());
        int n = nums.size();
        set<vector<int>> s;
        for(int i = 0 ; i<n-1 ; i++){
            int j = i+1;
            int k = n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum<0){
                    j++;
                }
                else if(sum>0){
                    k--;
                }
                else{
                    vector<int> temp = {nums[i],nums[j],nums[k]};
                    s.insert(temp);
                    j++;
                    k--;
                    while(j<k &&nums[j-1]==nums[j]){
                        j++;
                    }
                    while(j<k && nums[k]==nums[k+1]){
                        k--;
                    }
                }
            }
            while(i+1 < n && nums[i]==nums[i+1]){
                i++;
            }
        }
        vector<vector<int>> ans(s.begin(),s.end());
        return ans;

        // TC -> O(n^2) , SC -> O(n)
    }
};