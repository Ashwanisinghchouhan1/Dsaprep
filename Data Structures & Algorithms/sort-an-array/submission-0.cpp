class Solution {
public:
    /* =========================================================
     * ALGORITHM INTUITION & APPROACH: MERGE SORT
     * =========================================================
     * 1. Divide: Recursively split the array into two halves 
     *    around the midpoint until sub-arrays of size 0 or 1 are reached.
     * 2. Conquer: Sort each half independently via recursion.
     * 3. Combine (Merge): Stitch the two sorted halves back together 
     *    using two pointers into a temporary merged arrangement, maintaining 
     *    stability (l[i] <= r[j]).
     * 
     * TIME COMPLEXITY:
     * - Best, Average, and Worst Case: O(N log N)
     *   The recursion tree has a height of log(N), and at each level, 
     *   merging elements takes linear time O(N).
     * 
     * SPACE COMPLEXITY:
     * - Auxiliary Space: O(N)
     *   Temporary arrays 'l' and 'r' are allocated at each merge step to hold 
     *   sub-array copies, along with O(log N) stack space for recursion.
     * ========================================================= */

    void merge(vector<int>& arr, int s, int e, int mid) {
        int n1 = mid - s + 1;
        int n2 = e - mid;

        vector<int> l(n1), r(n2);
        for (int i = 0; i < n1; i++) l[i] = arr[s + i];
        for (int i = 0; i < n2; i++) r[i] = arr[mid + 1 + i];

        int i = 0, j = 0;
        int k = s;
        while (i < n1 && j < n2) {
            if (l[i] <= r[j]) {
                arr[k++] = l[i++];
            } else {
                arr[k++] = r[j++];
            }
        }

        while (i < n1) arr[k++] = l[i++];
        while (j < n2) arr[k++] = r[j++];
    }

    void mrgesort(vector<int>& arr, int s, int e) {
        if (s >= e) {
            return;
        }
        int mid = s + (e - s) / 2;
        mrgesort(arr, s, mid);
        mrgesort(arr, mid + 1, e);
        merge(arr, s, e, mid);
    }

    vector<int> sortArray(vector<int>& nums) {
        // Quick safeguard for empty or single-element arrays
        if (nums.empty()) return nums;
        
        int n = nums.size() - 1;
        mrgesort(nums, 0, n);
        return nums;
    }
};
