class Solution {
public:
    void merge(int s, int e, vector<int>& nums) {
        if (s >= e) return;
        int mid = (s + e) / 2;
        int len1 = mid - s + 1;
        int len2 = e - mid;
        vector<int> first(len1);
        vector<int> second(len2);
        int k = s;
        for (int i = 0; i < len1; i++) {
            first[i] = nums[k++];
        }
        k = mid + 1;
        for (int i = 0; i < len2; i++) {
            second[i] = nums[k++];
        }
        int idx1 = 0, idx2 = 0;
        k = s;
        while (idx1 < len1 && idx2 < len2) {
            if (first[idx1] < second[idx2]) {
                nums[k++] = first[idx1++];
            } else {
                nums[k++] = second[idx2++];
            }
        }
        while (idx1 < len1) {
            nums[k++] = first[idx1++];
        }
        while (idx2 < len2) {
            nums[k++] = second[idx2++];
        }
    }

    int count(int s, int mid, int e, vector<int>& nums) {
        int cnt = 0;
        int j = mid + 1;
        for (int i = s; i <= mid; i++) {
            while (j <= e && static_cast<long long>(nums[i]) > 2LL * nums[j]) {
                j++;
            }
            cnt += (j - (mid + 1));
        }
        return cnt;
    }

    int mergeSort(int s, int e, vector<int>& nums) {
        if (s >= e) return 0;
        int mid = (s + e) / 2;
        int cnt = mergeSort(s, mid, nums);
        cnt += mergeSort(mid + 1, e, nums);
        cnt += count(s, mid, e, nums);
        merge(s, e, nums);
        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(0, nums.size() - 1, nums);
    }
};
