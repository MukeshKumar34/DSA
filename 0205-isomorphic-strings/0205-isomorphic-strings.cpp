class Solution {
public:
    bool isIsomorphic(string s, string t) {
      vector<int>m(256,-1);
      vector<int>m1(256,-1);
      for(int i=0;i<s.length();i++){
        if(m[s[i]] != m1[t[i]]){
            return 0;
        }
        m[s[i]] = i;
        m1[t[i]] = i;
      }
      return 1;
    }
};