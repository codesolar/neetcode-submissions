class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0, res = INT_MAX, sum = 0;
        while(r < nums.size()){
            while(r < nums.size()){
                sum += nums[r];
                if(sum >= target) break;
                r ++;
            }
            if(r == nums.size()) break;
            res = min(res, r - l + 1);
            while(l <= r){
                sum -= nums[l];
                l ++;
                if(sum < target) break;
                res = min(res, r - l + 1);
            }
            r ++;
        }
        if(res == INT_MAX) return 0;
        return res;
    }
};