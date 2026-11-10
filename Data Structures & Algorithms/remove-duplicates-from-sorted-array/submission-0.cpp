class Solution {
public:
    /*
     * Approach & Intuition (Two Pointers / In-Place Overwrite):
     * Since the array is already sorted in ascending order, all duplicates 
     * of any element will appear sequentially next to each other.
     * 
     * 1. Two-Pointer Strategy: 
     *    - Pointer `ans` (starts at 1) tracks the index where the next unique element 
     *      should be placed. It also serves as the running count of unique elements.
     *    - Pointer `i` iterates through the array starting from index 1.
     * 2. When `nums[i] != nums[i - 1]`, we have encountered a new unique element.
     * 3. We place this unique element at `nums[ans]` and increment `ans`.
     * 4. If `nums[i] == nums[i - 1]`, it is a duplicate, so we simply skip it.
     * 5. Return `ans`, which represents the total count of unique elements.
     */
    int removeDuplicates(vector<int>& nums) {
        int ans = 1;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {
                nums[ans++] = nums[i]; // Store unique element and move pointer
            }
        }

        return ans;
    }
};
