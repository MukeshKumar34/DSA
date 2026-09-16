class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
       int m =-1;

       for(int i=arr.size()-1;i>=0;i--){
        int temp = arr[i];
        arr[i] = m;
         m = max(m,temp);
       }
       return arr;
    }
};