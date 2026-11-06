class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        
        unordered_map<int , int>freq;
        for(int n : nums){
            freq[n]++;
        }
        for(int n : nums){
            if(freq[n] > 1)
            return true;
        }
        return false;
    }
};