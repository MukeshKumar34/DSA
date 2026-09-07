class Solution {
public:
    vector<int> plusOne(vector<int>& v) {
        int n = v.size();
       for(int i=n-1;i >=0;i--){

        if(v[i] < 9){
            v[i]++;
            return v;
        }
     v[i] =0;
       }
 v.insert(v.begin(),1);
 return v;
       
    }
};