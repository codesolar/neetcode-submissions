class Solution {
public:
    int fun(vector<int>& nums, int target, int l, int r){
        if(l > r) return -1;
        int mid = l + (r - l)/2;
        if(nums[mid] > target){
            return fun(nums, target, l, mid - 1);
        }
        else if(nums[mid] < target){
            return fun(nums, target, mid + 1, r);
        }
        else if(nums[mid] == target){
            return mid;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int mid = -1;
        while(l <= r){
            mid = l + (r - l)/2;
            if(nums[mid] > target){
                r = mid - 1;
            }
            else if(nums[mid] < target){
                l = mid + 1;
            }
            else if(nums[mid] == target){
                return mid;
            }
        }
        
        return -1;
    }
};
