class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // vector<int> nextGreaterElement(nums1.size(),-1);
        // for(int i = 0 ;i<nums1.size(); i++){
        //     int j = 0;
        //     for(j = 0 ; j<nums2.size(); j++){
        //         if(nums1[i] == nums2[j]){
        //             break;
        //         }
        //     }
        //     while(j<nums2.size() && nums2[j]<=nums1[i]){
        //         j++;
        //     }
        //     if(j!= nums2.size()){
        //         nextGreaterElement[i] = nums2[j];
        //     }
        // }
        // return nextGreaterElement;

        stack<int> st;
        vector<int> nextGreaterElement(nums2.size());

        for(int i = nums2.size()-1; i>=0 ; i--){

            if(st.empty()){
                nextGreaterElement[i] = -1;
                st.push(nums2[i]);
            }
            else if(st.top() > nums2[i]){
                nextGreaterElement[i] = st.top();
                st.push(nums2[i]);
            }
            else{
                while(!st.empty() && st.top()<=nums2[i]){
                    st.pop();
                }
                if(st.empty()){
                    nextGreaterElement[i] = -1;
                }
                else{
                    nextGreaterElement[i] = st.top();
                }
                st.push(nums2[i]);
            }
        }

        vector<int> ans;
        for(int i = 0 ; i<nums1.size(); i++){
            int x = find(nums2.begin(), nums2.end() ,nums1[i]) - nums2.begin();
            ans.push_back(nextGreaterElement[x]);
        }

        return ans;
    }
};