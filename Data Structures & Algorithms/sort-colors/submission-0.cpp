class Solution {
public:
 void sort(vector<int>& arr){
    int n = arr.size();
   for (int i = 1; i < n; i++)
    {
         bool swapped = false;
        /* code */
        for (int j = 0; j < n-i; j++)
        {
            /* code */
            if (arr[j + 1] < arr[j])
            {
                /* code */
                swap(arr[j+1] , arr[j]);
                swapped = true;
            }
            
        }
        if (swapped == false)
        {
            /* code */
            break;
        }
        
        
    }
 }
    void sortColors(vector<int>& nums) {
        sort(nums);
       
    
    }
};