class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
      unordered_map<int , int>m;
      int maxcount = 0;
      int ans = 0;
      for(int n : nums){
        m[n]++;
        if(m[n] > maxcount){
            ans = n;
            maxcount = m[n];
        }
      }  
    return ans;
    }
};