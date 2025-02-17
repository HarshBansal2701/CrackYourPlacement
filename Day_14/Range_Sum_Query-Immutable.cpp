class NumArray {
    vector<int> sumArr;
public:
    NumArray(vector<int>& nums) {
        int sum = 0;
        for(int i = 0 ; i<nums.size(); i++){
            sum += nums[i];
            sumArr.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        if(left ==0){
            return sumArr[right];
        }
        return (sumArr[right]-sumArr[left-1]);
    }
};