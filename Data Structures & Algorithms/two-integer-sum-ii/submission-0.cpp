class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int left = 0, right = n-1;
        while(left < right) {
            if(numbers[left] == target - numbers[right])
                return {left+1, right+1};
            if(numbers[left] > target - numbers[right])
                right--;
            if(numbers[left] < target - numbers[right])
                left++;
        }
        return {};
    }
};
