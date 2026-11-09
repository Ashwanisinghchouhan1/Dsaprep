class Solution {
public:
    /*
     * Approach & Intuition:
     * We need to find the index of a target value in a sorted array in O(log n) time.
     * If the target is not present, we return the index where it should be inserted.
     * 
     * 1. Binary Search Strategy: Maintain two pointers, `s` (start = 0) and `e` (end = n - 1).
     * 2. In each iteration, calculate the midpoint: `mid = s + (e - s) / 2`.
     * 3. If `nums[mid] == target`, we found the target, so return `mid`.
     * 4. If `nums[mid] > target`, the target must lie in the left half, so update `e = mid - 1`.
     * 5. If `nums[mid] < target`, the target lies in the right half, so update `s = mid + 1`.
     * 6. When the loop terminates (`s > e`), the start pointer `s` automatically points to 
     *    the exact position where the target should be inserted to maintain sorted order.
     */
    int searchInsert(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] == target) {
                return mid; // Target found
            }

            if (nums[mid] > target) {
                e = mid - 1; // Search left half
            } else {
                s = mid + 1; // Search right half
            }
        }

        // 's' points to the correct insertion index when target is not found
        return s; 
    }
};
