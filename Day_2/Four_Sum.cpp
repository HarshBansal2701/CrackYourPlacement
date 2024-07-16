class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // Approach -> Sorting , Four Pointer 
        // Same as 2Sum and 3Sum we just need to add one extra pointer
        sort(nums.begin(), nums.end());

        if (nums.size() < 4) {
            return {};
        }
        set<vector<int>> ans;

        for (int i = 0; i < nums.size()-3; i++) {
            for (int j = i + 1; j < nums.size()-2; j++) {
                int k = j + 1;
                int l = nums.size() - 1;

                while (k < l) {
                    long x = (long)nums[i] + (long)nums[j] + (long)nums[k] + (long)nums[l];
                    if (x == target) {
                        ans.insert({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                    } else if (x > target) {
                        l--;
                    } else {
                        k++;
                    }
                }
            }
        }
        vector<vector<int>> res(ans.begin(), ans.end());
        return res;

        // TC -> O(n^3) , SC -> O(n)
    }
};