class Solution {
public:
    long long  ans = 0;
    long long d= 0;
    void merge(vector<int> &v, int start, int mid, int end) {
 
        vector<int> v1;
        vector<int> v2;
        for(int i = start; i <= mid; i++) {
            v1.push_back(v[i]);
        }
        
        for(int i = mid + 1 ; i <= end; i++) {
            v2.push_back(v[i]);
        }

        int i =0 , j = 0, k =start;
        while(j < v2.size()) {
            while(i < v1.size() && v1[i] - d <= v2[j]) {
                i++;
            }
            ans += i;
            j++;
        }

        i =0, j = 0;

        while(i < v1.size() && j < v2.size()) {
            if(v1[i] < v2[j]) {
                v[k++] = v1[i++];
            } else {
                v[k++] = v2[j++];
            }
        }
        while(i < v1.size()) {
            v[k++] = v1[i++];
        }
        while(j < v2.size()) {
            v[k++] = v2[j++];
        }

    }

    void mergeSort(vector<int> &v, int start ,int end){
        if(start >= end) {
            return;
        }
        int mid = (start + end) / 2;
        mergeSort(v, start, mid);
        mergeSort(v, mid + 1, end);
        merge(v, start,mid, end);
    }

    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();

        vector<int> v(n);
        d = diff;

        for(int i =0; i < n; i++) {
            v[i] = nums1[i] - nums2[i];
        }



        mergeSort(v,0,n-1);
        return ans;
    }
};
