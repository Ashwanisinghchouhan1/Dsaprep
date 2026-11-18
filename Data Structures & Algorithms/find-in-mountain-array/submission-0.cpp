/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        if(mountainArr.length() < 3)return -1;
           
    int s = 0, e = mountainArr.length() - 1;
    while (s < e) {
        int mid = s + (e - s) / 2;
        if (mountainArr.get(mid) < mountainArr.get(mid + 1))
            s = mid + 1;
        else
            e = mid;
    }
        int peak = s;

         s = 0 , e = peak;
         while(s <= e){
            int mid = s + (e - s) / 2;
            int val = mountainArr.get(mid);
            if(val == target)return mid;
            if(val < target)s = mid +1;
            else e = mid -1;
 
         }

         s = peak + 1 , e = mountainArr.length()-1;
         while(s <= e){
            int mid = s + (e - s) / 2;
            int val = mountainArr.get(mid);
            if(val == target)return mid;
            if(val < target)s = mid +1;
            else e = mid -1;
 
         }
         return -1;
    }
};