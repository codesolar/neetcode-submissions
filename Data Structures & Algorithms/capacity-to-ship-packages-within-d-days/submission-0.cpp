class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);
        int result = INT_MAX, res_days = 0, res = 0;
        int mid = -1, i = 0;
        while(l <= r){
            mid = (l + r)/2;
            i = 0;
            res = 0;
            res_days = 0;
            while(i < weights.size()){
                if(res + weights[i] <= mid){
                    res += weights[i];
                }
                else{
                    res_days ++;
                    res = weights[i];
                }
                i ++;
            }
            if(res != 0) res_days ++;

            if(res_days > days){
                l = mid + 1;
            }
            else if(res_days <= days){
                r = mid - 1;
                result = min(result, mid);
            }
        }
        return result;
    }
};