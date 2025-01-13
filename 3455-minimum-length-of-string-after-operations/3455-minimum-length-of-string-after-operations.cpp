class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26, 0);
        for(auto& ch : s)
        {
            freq[ch - 'a']++;
        }
        int ans = 0;
        for(auto& c : freq)
        {
            if(c)
            {
                ans += c % 2 ? 1 : 2;
            }
        }
        return ans;
    }
};