/*
    Design a class to find the kth largest element in a stream

    Min heap & maintain only k elements, top will always be kth largest
    Ex. nums = [6,2,3,1,7], k = 3 -> [1,2,3,6,7] -> [3,6,7]

    Time: O(n log n + m log k) -> n = length of nums, m = add calls
    Space: O(n)
*/

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

// Solution1 (My implementation)
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        int n = nums.size();
        for (int i=0; i<n; i++) {
            pq.push(nums[i]);
        }
    }
    
    int add(int val) {
        pq.push(val);
        while (pq.size() > this->k) {
            pq.pop();
        }
        return pq.top();
    }
    
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;
};



// Solution2 (NeetCode)
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }
        while (pq.size() > this->k) {
            pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > k) {
            pq.pop();
        }
        return pq.top();
    }
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;
};



// Solution3 (NeetCode) based on "Quickselect" (use the partition method of quick sort)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int low=0;
        int high=nums.size()-1;
        int pivot_index = nums.size();
        while (pivot_index != k-1) {
            pivot_index = partition(nums, low, high);
            if (pivot_index > k-1) {
                high = pivot_index - 1;
            }
            if (pivot_index < k-1) {
                low = pivot_index + 1;
            }
        }
        // return nums[k-1];
        return nums[pivot_index];
    }
private:
    int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[low];
        int l = low + 1;
        int r = high;
        
        while (l<=r) {
            if (nums[l]<pivot && pivot<nums[r]) {
                swap(nums[l], nums[r]);
            }
            if (nums[l]>=pivot) {
                l++;
            }
            if (nums[r]<=pivot) {
                r--;
            }

            //如下寫法亦可
            // if (arr[l]<pivot && pivot<arr[r]) {
            //     swap(arr[l], arr[r]);
            //     l++;
            //     r--;
            // }
            // if (arr[l]>=pivot) {
            //     l++;
            // }
            // if (arr[r]<=pivot) {
            //     r--;
            // }
        }
        swap(nums[low], nums[r]);
        return r;
    }
};
