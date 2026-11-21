class Solution {
public:
    int findMin(vector<int> &nums) {
        if(nums.size() == 1) return nums[0];
        int l = 0, r = nums.size() - 1;
        int mid = -1;
        int res = INT_MAX;
        // cout << (-1) % 1<<endl;
        while(l <= r){
            mid = (l + r)/2;
            if(l == r) return min(res, nums[l]);
            else if(nums[l] < nums[r]) return min(res, nums[l]);
            else if(nums[mid] > nums[r]) l = mid + 1;
            else if(nums[mid] < nums[r]){
                res = min(res, nums[mid]);
                r = mid - 1;
            }
        }
        return res;
    }
};
