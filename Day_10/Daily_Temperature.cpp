class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> ans(temperatures.size());
        for(int i = temperatures.size()-1 ; i>=0 ; i--){
            if(st.empty()){
                ans[i] = 0;
                st.push(i);
            }
            else if(temperatures[st.top()]> temperatures[i]){
                ans[i] = st.top()-i;
                st.push(i);
            }
            else{
                while(!st.empty() && temperatures[st.top()]<= temperatures[i]){
                    st.pop();
                }

                if(st.empty()){
                    ans[i] = 0;
                }
                else{
                    ans[i] = st.top() -i;
                }
                st.push(i);
            }
        }
        return ans;
    }
};