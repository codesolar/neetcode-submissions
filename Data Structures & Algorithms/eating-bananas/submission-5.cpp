class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long l = 1, r = 1000000000;
        long long p = 1000000000;
        long long mid = -1, res = 0;
        while(l <= r){
            res = 0;
            mid = l + (r - l)/2;
            for(int i = 0; i < piles.size(); i ++){
                res += (long long)(ceil((1.0 * piles[i])/mid));
            }
            if(res > h){
                l = mid + 1;
            }
            else if(res <= h){
                r = mid - 1;
                p = min(p, mid);
            }
        }
        return p;
    }
};
