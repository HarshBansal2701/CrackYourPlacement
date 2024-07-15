class Solution {
public:
    void sortColors(vector<int>& nums) {
       // METHOD-1 (using in-built sort function)

    //    sort(nums.begin(), nums.end());

    //    Method-1 => TC - O( n*log(n) )



    // Method-2 (find frequency and modify original array)

    // int zero = 0;
    // int one = 0;
    // for(int i = 0 ; i<nums.size(); i++){
    //     if(nums[i]==0){
    //         zero++;                       //count freq of zero
    //     }
    //     else if(nums[i]==1){
    //         one++;                        // count freq of two
    //     }
    // }
    // for(int i = 0 ; i<zero ; i++){
    //     nums[i] = 0;                     //modify the array according to the count of zero
    // }
    // for(int i = zero ; i<(zero+one) ; i++){
    //     nums[i] = 1;                    //modify the array according to the count of one 
    // }
    // for(int i = (zero+one) ; i< nums.size(); i++){
    //     nums[i] = 2;                    // rest element are two
    // }
    
    // Method-2 => TC - O(n);


    // Method-3 (three pointer approach , track the index of zero, one, two)

    int start = 0;
    int mid = 0;
    int end = nums.size()-1;

    while(mid<=end){
        if(nums[mid] == 0){                    
            swap(nums[start++],nums[mid++]);
        }
        else if(nums[mid]==2){
            swap(nums[mid], nums[end--]);
        }
        else{
            mid++;
        }
    }
    // Method-3 => TC - O(n)
    }
};