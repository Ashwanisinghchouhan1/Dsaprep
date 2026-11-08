class Solution {
public:
    /*
     * Approach & Intuition:
     * To determine if an array contains any duplicate elements:
     * 1. We can use a hash map (`unordered_map<int, int>`) to keep track of the frequency of each integer.
     * 2. In the first pass, we iterate through the `nums` array and increment the count for each number.
     * 3. In the second pass, we check if any number has a frequency strictly greater than 1.
     *    If we find one, it means a duplicate exists, so we return `true`.
     * 4. If we finish checking all elements without finding any frequency > 1, we return `false`.
     */
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> freq;
        
        // Pass 1: Count the frequency of each element
        for (int n : nums) {
            freq[n]++;
        }
        
        // Pass 2: Check for any duplicates
        for (int n : nums) {
            if (freq[n] > 1) {
                return true;
            }
        }
        
        return false;
    }
};
