class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>temp(nums.size());
        
       int pre = 1;
       for(int i = 0; i < nums.size(); i++){
        temp[i] = pre;
        pre *= nums[i];
       }

       int post = 1;
       for(int i = nums.size() -1; i >= 0; i--){
        temp[i] *= post;
        post *= nums[i];
       }
      return temp;
    }
};
