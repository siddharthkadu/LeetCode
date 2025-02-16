class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> res(2 * n - 1, 0);
        vector<bool> used(n + 1, false);
        backtrack(0, res, used, n);
        return res;
    }

private:
    bool backtrack(int idx, vector<int>& res, vector<bool>& used, int n) {
        if (idx == res.size()) return true;
        if (res[idx] != 0) return backtrack(idx + 1, res, used, n);
        
        for (int num = n; num >= 1; --num) {
            if (used[num]) continue;
            int pos = (num == 1) ? idx : idx + num;
            if (pos >= res.size() || res[pos] != 0) continue;
            
            res[idx] = res[pos] = num;
            used[num] = true;
            if (backtrack(idx + 1, res, used, n)) return true;
            res[idx] = res[pos] = 0;
            used[num] = false;
        }
        return false;
    }
};