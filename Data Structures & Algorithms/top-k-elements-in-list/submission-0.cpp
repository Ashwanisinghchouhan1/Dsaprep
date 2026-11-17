class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int>count;
        for(int n : nums){
            count[n]++;
        }
        
        vector<vector<int>>freq(nums.size()+1);
        for(const auto& pair: count){
            int num = pair.first;
            int cnt = pair.second;
            freq[cnt].push_back(num);
        }

        vector<int>ans;
        for(int i = freq.size()-1; i > 0; i--){
            for(int n : freq[i]){
                ans.push_back(n);
                if(k == ans.size())
                return ans;
            }
        }      
        return ans;
    }
};
