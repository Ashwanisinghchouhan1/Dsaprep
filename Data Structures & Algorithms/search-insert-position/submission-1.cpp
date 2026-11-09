class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size()-1;
        int res = nums.size();
        while(s <= e){
           int mid = s + (e-s)/2;
            if(nums[mid] == target)
            return mid;

            if(nums[mid] > target){
                res = mid;
                e = mid -1;
            }
            else{
                s = mid + 1;
            }
            mid = s + (e-s)/2;
        }
     return res;
    }
};