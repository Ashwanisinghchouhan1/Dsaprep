class Solution {
public:
    /*
     * Approach & Intuition (Two-Pointer Technique):
     * Since the input array `numbers` is already sorted in ascending order, we can 
     * efficiently find the two numbers that sum up to the target using two pointers:
     * 
     * 1. Initialize pointer `i` at the beginning (0) and pointer `j` at the end (n - 1).
     * 2. In each iteration, calculate the `sum = numbers[i] + numbers[j]`.
     * 3. If `sum == target`, we found our pair! Return 1-based indices `{i + 1, j + 1}`.
     * 4. If `sum > target`, the sum is too large, so decrement `j` (`j--`) to decrease the sum.
     * 5. If `sum < target`, the sum is too small, so increment `i` (`i++`) to increase the sum.
     */
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;

        while (i < j) {
            int sum = numbers[i] + numbers[j];

            if (sum == target) {
                return {i + 1, j + 1}; // Return 1-based indices as required
            }
            
            if (sum > target) {
                j--; // Sum is too large, move right pointer left
            } else {
                i++; // Sum is too small, move left pointer right
            }
        }

        return {}; // Return empty vector if no solution exists (though guaranteed by constraints)
    }
};
