class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, res = 0;
        unordered_map<char, int> map;
        while(r < s.size()){
            if(map.find(s[r]) != map.end() and map[s[r]] >= l){
                res = max(res, r - l);
                l = map[s[r]] + 1;
                map[s[r]] = r;
            }
            else{
                map[s[r]] = r;
            }
            r ++;
        }
        return max(r - l, res);
    }
};
