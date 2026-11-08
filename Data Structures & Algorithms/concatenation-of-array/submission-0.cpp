class Solution {
public:
    /*
     * Approach & Intuition:
     * To concatenate an array with itself (ans = nums + nums):
     * 1. We need an output vector of size 2 * n, where n = nums.size().
     * 2. The elements at index i and (i + n) should both receive nums[i].
     * 3. Instead of using push_back in separate loops, we can allocate the full size upfront
     *    and populate both halves in a single traversal, or simply duplicate the push_back pass.
     */
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2 * n);

        for (int i = 0; i < n; ++i) {
            ans[i] = nums[i];       // First copy (indices 0 to n-1)
            ans[i + n] = nums[i];   // Second copy (indices n to 2n-1)
        }

        return ans;
    }
};
