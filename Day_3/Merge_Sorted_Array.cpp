class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // // Method -1 (using an extra array)
        // vector<int> ans;
        // int i=0;
        // int j=0;
        // while(i<m && j<n){
        //     if(nums1[i]<nums2[j]){
        //         ans.push_back(nums1[i++]);
        //     }
        //     else{
        //         ans.push_back(nums2[j++]);
        //     }
        // }
        // while(i<m){
        //     ans.push_back(nums1[i++]);
        // }
        // while(j<n){
        //     ans.push_back(nums2[j++]);
        // }
        // nums1 = ans;
        // // TC-> O(m+n) , SC -> O(m+n)


        // Method-2 (Modify the nums1 array , without using extra space)
        int index1 = m-1;
        int index2 = n-1;                       // Initialising 
        int index = m+n-1;

        while(index1 >=0 && index2>=0){
            if(nums1[index1] >= nums2[index2]){
                nums1[index--] = nums1[index1--];              // merging 
            }
            else{
                nums1[index--] = nums2[index2--];
            }
        }

        while(index2>=0){
            nums1[index--] = nums2[index2--];                  // copy remianing 
        }

        // TC -> O(m+n) , SC -> O(1)
    }
};