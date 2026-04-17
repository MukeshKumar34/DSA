class Solution {
public:
    bool isAnagram(string s, string t) {
       if(s.length() != t.length()){
        return 0;
       }
        vector<int> ans(26,0);
            for(int i=0;i<s.length();i++){
                ans[s[i]-'a']++;
                ans[t[i]-'a']--;
}
for(int count : ans){
    if(count != 0){
        return 0;
    }
}
return 1;
    }
};