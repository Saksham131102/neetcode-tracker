class Solution {
private:
    int findPivot(vector<int> &nums) {
        int n = nums.size();
        int left = 0, right = n - 1;

        while(left <= right) {
            int mid = left + (right - left) / 2;
            // means the array is not in cyclic manner
            if(mid == n - 1) {
                return mid;
            }
            // if mid does not reach n-1 that means it is
            // in cyclic manner
            if(nums[mid] > nums[mid+1])
                return mid;
            
            if(nums[0] <= nums[mid]) {
                left = mid + 1;
            }
            else if(nums[0] > nums[mid]) {
                right = mid - 1;
            }
        }
        return -1;
    }
    int BS(vector<int> &nums, int left, int right, int target) {
        int ans = -1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) {
                ans = mid;
                break;
            }
            if(nums[mid] < target) {
                left = mid + 1;
            }
            if(nums[mid] > target) {
                right = mid - 1;
            }
        }
        return ans;
    }
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int pivotIdx = findPivot(nums);

        if(nums[0] <= target) {
            return BS(nums, 0, pivotIdx, target);
        }
        else {
            return BS(nums, pivotIdx + 1, n-1, target);
        }
    }
};
