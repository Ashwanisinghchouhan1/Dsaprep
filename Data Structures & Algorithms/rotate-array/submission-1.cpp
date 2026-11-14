class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
       for(int i = 0; i < n / 2; i++){
         swap(nums[(i + k) % n] , nums[i]);
       }
    }
};