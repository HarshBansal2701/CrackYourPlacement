class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // // #Method-1 -> tracking the frequency of the element

        // unordered_map<int,int> freq;
        // for(int i = 0 ; i<nums.size(); i++){
        //     freq[nums[i]]++;
        //     if(freq[nums[i]] > 1){   // whenever the frequency greater then 1 i.e. element is repeated
        //         return nums[i];    
        //     }
        // }
        // return -1;

        // // Method1 -> TC = O(n) , SC = O(n)



        // //Method-2 -> by making a boolean visited array 

        // vector<bool> vis(nums.size(), false);
        // for(int i = 0 ; i<nums.size(); i++){
        //     if(!vis[nums[i]]){             // if element is not visited previously mark it visited
        //         vis[nums[i]] = true;
        //     }
        //     else{                         // if element is visited previously return it
        //         return nums[i];
        //     }
        // }
        // return -1;

        // // Method-2 TC = O(n) , SC = O(n)
        // // better then method one bcose 
        // // 1 -> asignment operation (vis[nums[i]] = true) takes less time then increment operator (freq[nums[i]]++)
        // // 2 -> boolen value takes less space then integer value 
        


        // //Method-3 (Playing with indexes)
        // // use element as indexs and make then -ve that shows element is visited

        for(int i = 0 ; i<nums.size(); i++){
            if(nums[abs(nums[i])]<0){
                return abs(nums[i]);
            }
            else{
                nums[abs(nums[i])] = -nums[abs(nums[i])];
            }
        }
        return -1;
        // // Method-3 TC = O(n) , SC = O(1) -> optimized qpproach
    }
};