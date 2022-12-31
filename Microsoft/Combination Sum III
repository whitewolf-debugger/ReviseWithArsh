class Solution {
public:
    int makeKey(vector<int> &arr) {
        int key =0;
        for(int i =0; i < arr.size(); i++) {
            key = key * 10 + arr[i];
        }
        return key;
    }
    void getAns(int n, int k, vector<int> path, vector<vector<int>> &ans, unordered_set<int> &seen, int start,unordered_set<int> keys) {
        if(k == 0) {
            if(n == 0) {
                int key = makeKey(path);
                if(keys.find(key) == keys.end()) {
                    keys.insert(key);
                    ans.push_back(path);
                }
                
            }
            return;
        }
        if(n <= 0) return;

        for(int i = start; i <= 9; i++) {
            if(seen.find(i) == seen.end()){
                n-=i;
                k-=1;
                seen.insert(i);
                path.push_back(i);
                getAns(n,k,path,ans,seen, i + 1,keys);
                path.pop_back();
                k+=1;
                n+=i;
                seen.erase(i);
            }
            
        }
        
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        unordered_set<int> keys;
        vector<vector<int>> ans;
        unordered_set<int> seen;
        vector<int> path;
        getAns(n, k, path, ans, seen, 1,keys);
        return ans;
    }
};
