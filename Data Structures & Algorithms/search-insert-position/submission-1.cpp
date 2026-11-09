class Solution {
public:
    /*
     * Approach & Intuition:
     * We need to find the index of a target value in a sorted array, or the index 
     * where it would be inserted if it isn't present, in O(log n) time.
     * 
     * 1. Binary Search Strategy: Since the array `nums` is strictly sorted in ascending order, 
     *    we can maintain two pointers: `s` (start) and `e` (end).
     * 2. Variable `res` tracks the potential insertion position, initialized to `nums.size()` 
     *    (handling cases where target is greater than all existing elements).
     * 3. At each step, calculate the midpoint: `mid = s + (e - s) / 2`.
     * 4. If `nums[mid] == target`, we return `mid` immediately.
     * 5. If `nums[mid] > target`, it means target must reside on the left half (or at `mid`).
     *    We record `res = mid` as a candidate insertion index and shrink our search window (`e = mid - 1`).
     * 6. If `nums[mid] < target`, target lies in the right half, so we update `s = mid + 1`.
     * 7. Loop terminates when `s > e`, returning `res`.
     */
    int searchInsert(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;
        int res = nums.size(); // Default insertion index if target > all elements

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] == target) {
                return mid; // Target found
            }

            if (nums[mid] > target) {
                res = mid;     // Record mid as candidate insertion index
                e = mid - 1;   // Search left half
            } else {
                s = mid + 1;   // Search right half
            }
        }

        return res;
    }
};
