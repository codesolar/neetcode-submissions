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
        return  fun(nums, target, 0, nums.size() -1);
    }
};
