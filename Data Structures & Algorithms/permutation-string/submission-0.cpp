class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.size(), l2 = s2.size();
        if(l1 > l2) return false;
        int l = 0, r = 0;
        int v1[26] = {0}, v2[26] = {0};
        for(int i = 0; i < l1; i ++){
            v1[s1[i] - 'a'] ++;
        }
        
        while(r < l1){
            v2[s2[r] - 'a'] ++;
            r ++;
        }
        bool found = 1;
        for(int i = 0; i < 26; i ++){
            if(v1[i] != v2[i]){
                found = 0;
                break;
            } 
        }

        if(found == 1) return true;
        while(r < l2){
            v2[s2[r] - 'a'] ++;
            v2[s2[l] - 'a'] --;
            l ++;
            r ++;
            found = 1;
            for(int i = 0; i < 26; i ++){
                if(v1[i] != v2[i]){
                    found = 0;
                    break;
                } 
            }
            if(found == 1) return true;
        }
        return false;
    }
};
