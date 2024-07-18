class Solution {
    vector<int> nextSmall(vector<int>& heights){
        vector<int> ps(heights.size());
        stack<int> st;

        for(int i = heights.size()-1 ; i>=0; i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                ps[i] = -1;
            }
            else{
                ps[i] = st.top();
            }
            st.push(i);
        }
        return ps;
    }
    vector<int> prevSmall(vector<int>& heights){
        vector<int> ps(heights.size());
        stack<int> st;

        for(int i = 0 ; i<heights.size(); i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                ps[i] = -1;
            }
            else{
                ps[i] = st.top();
            }
            st.push(i);
        }
        return ps;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        // Approach
        // make 2 vector of previous small and next small element of ith element
        // find the max value of (nextSmall[i]-prevSamll[i]-1)*height[i] 

        vector<int> prevS = prevSmall(heights);
        vector<int> nextS = nextSmall(heights);
        int ans = -1;
        for(int i = 0 ; i<heights.size(); i++){
            if(nextS[i]==-1){
                nextS[i] = heights.size();
            }
            ans = max(ans,(nextS[i]-prevS[i]-1)*heights[i]);
        }
        return ans;

        // tc -> O(N)
    }
};