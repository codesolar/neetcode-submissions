class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        long long mid = -1;
        while(l <= r){
            mid = l + (r - l)/2;
            long long val = mid * mid;
            if(val == x) return mid;
            if(val < x){
                l = mid + 1;
            }
            else if(val > x){
                r = mid - 1;
            }
        }
        return r;
    }
};