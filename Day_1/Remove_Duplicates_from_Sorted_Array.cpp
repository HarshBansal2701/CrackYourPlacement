class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Method-1 (erase duplicate element)

        // int i = 0;                              // to track the size of unique element 
        // int n = nums.size();                    // to store the length of original array before modification
        // for(int j = 0 ; j<nums.size()-1; j++){
        //     if(nums[j]==nums[j+1]){             // when two adjacent element are same erase one of them 
        //         nums.erase(nums.begin()+j);
        //         j--;
        //         i++;                                                    
        //     }
            
        // }
        // return (n-i);
        // // Method-1 => TC - O(n^2);


        // // Method-2 (Using Set)
        
        // set<int> st;
        // for(int i = 0 ; i<nums.size(); i++){
        //     st.insert(nums[i]);               // Store unique elements
        // }
        // int index = 0;
        // for(auto it : st){
        //     nums[index++] = it;               // update the original array
        // }
        // return st.size();

        // // Method-2 => TC - O(n*log(n)) + extra space O(n)


        // Method-3 (track index of unique element)
        int i = 1;
        for(int j = 1 ; j<nums.size(); j++){
            if(nums[j] != nums[i-1]){
                swap(nums[j], nums[i]);     // when encounter unique element swap it 
                i++;
                
            }
        }
        return i;

        // Method-3 => TC - O(n) ans SC - O(1)
    }
};