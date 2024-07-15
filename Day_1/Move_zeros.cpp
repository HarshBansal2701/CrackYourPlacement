class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // Similar pattern of remove duplicate element from sorted array 
        // using two pointer 
        // one pointer iterate over the array and other points the element other then zero

        int j = 0 ;
        for(int i = 0 ; i<nums.size() ; i++){
            if(nums[i]==0){
                continue;
            }
            else{
                swap(nums[i],nums[j]);
                j++;
            }
        }

        // TC -> O(n) , SC - O(1)
    }
};