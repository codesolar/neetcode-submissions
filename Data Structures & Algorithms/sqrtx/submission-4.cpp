class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        if(x <= 1) return x;
        int mid = -1;
        while(l <= r){
            mid = l + (r - l)/2;
            int a = x/mid;
            if(a == mid) return mid;
            if(a < mid){
                r = mid - 1;
            }
            else if(a > mid){
                l = mid + 1;
            }
        }
        return r;
    }
};