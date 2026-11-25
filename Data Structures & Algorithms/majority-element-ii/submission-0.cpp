class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
      int cand1 = 0;
      int cand2 = 0;
      int count1 = 0;
      int count2 = 0;
      for(int num : nums){
        if(cand1 == num){
            count1++;
        }
        else if(cand2 == num){
            count2++;
        }
        else if(count1 == 0){
            cand1 = num;
            count1 = 1;
        }
        else if(count2 == 0){
            cand2 = num;
            count2 = 1;
        }
        else{
            count1--;
            count2--;
        }
      }

      int freq1 = 0;
      int freq2 = 0;
      for(int num : nums){
        if(cand1  == num)freq1++;
        else if(cand2  == num)freq2++;
      }  
     vector<int>ans;
      if(freq1 > nums.size()/3){
        ans.push_back(cand1);
      }
      if(freq2 > nums.size()/3){
        ans.push_back(cand2);
      }
      return ans;
    }
};