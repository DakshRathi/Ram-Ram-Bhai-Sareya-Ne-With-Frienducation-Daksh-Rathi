class Solution {
public:
    bool isIsomorphic(string s, string t) {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios_base::sync_with_stdio(false);
        
        if (s.size() != t.size()) return false;
        
        unordered_map<char, char> mapS2T, mapT2S;
        
        for (int i = 0; i < s.size(); i++) {
            char c1 = s[i];
            char c2 = t[i];
            
            // Check the mapping from s to t
            if (mapS2T.count(c1)) {
                if (mapS2T[c1] != c2) {
                    return false;
                }
            } else {
                mapS2T[c1] = c2;
            }
            
            // Check the mapping from t to s
            if (mapT2S.count(c2)) {
                if (mapT2S[c2] != c1) {
                    return false;
                }
            } else {
                mapT2S[c2] = c1;
            }
        }
        
        return true;
    }
};