class Solution {
public:
  
  void merge(vector<int>&arr , int s , int e, int mid){
      int n1 = mid - s + 1;
      int n2 = e - mid;
       
      vector<int>l(n1) , r(n2);

      for(int i = 0 ; i < n1 ; i++)
      l[i] = arr[s + i];

      for(int i = 0; i < n2; i++)
        r[i] = arr[mid + 1 + i];
      
      int i = 0 , j  = 0;
      int k = s;

      while(i < n1 && j < n2){
        if(l[i] <= r[j]){
            arr[k++] = l[i++];
        }
        else{
            arr[k++] = r[j++];
        }
      }
      while(i < n1)
      arr[k++] = l[i++];

       while(j < n2)
      arr[k++] = r[j++];
  }
   
   void mrgesort( vector<int>&arr , int s , int e){
    if(s >= e){
        return;
    }
    int mid = s + (e - s)/2;
    mrgesort(arr , s, mid);
    mrgesort(arr , mid + 1 , e);
     merge(arr , s , e , mid);
   }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size()-1;
        mrgesort(nums , 0 , n);
        return nums;
    }
};