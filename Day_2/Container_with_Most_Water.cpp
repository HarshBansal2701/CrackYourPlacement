class Solution {
public:
    int maxArea(vector<int>& height) {
        // Method (Two Pointers)
        // initialize two pointers one at starting index and other at end index
        // find area at each iteration and move pointers that has less height
        int i = 0;
        int j = height.size()-1;
        int maxArea = 0;
        while(i<j){
            maxArea = max(maxArea , (j-i)*(min(height[i], height[j])));
            if(height[i]>= height[j]){
                j--;
            }
            else{
                i++;
            }
        }
        return maxArea;

        // TC -> O(n) , SC -> O(1)
    }
};