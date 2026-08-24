class Solution {
private:
    void mergeSortedArray(vector<int> &nums, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<int> L(n1), R(n2);

        for(int i=0;i<n1;i++) {
            L[i] = nums[left+i];
        }
        for(int i=0;i<n2;i++) {
            R[i] = nums[mid+1+i];
        }

        int p1 = 0, p2 = 0;
        int idx = left;

        while(p1 < n1 && p2 < n2) {
            if(L[p1] <= R[p2])
                nums[idx++] = L[p1++];
            else
                nums[idx++] = R[p2++];
        }

        while(p1 < n1)
            nums[idx++] = L[p1++];
        while(p2 < n2)
            nums[idx++] = R[p2++];
    }
    void mergeSort(vector<int> &nums, int left, int right) {
        // base case
        if(left >= right)
            return;
        
        // recursive relation
        int mid = left + (right - left) / 2;
        // left merge
        mergeSort(nums, left, mid);
        // right merge
        mergeSort(nums, mid+1, right);
        // merge two sorted array
        mergeSortedArray(nums, left, mid, right);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums, 0, n-1);
        return nums;
    }
};