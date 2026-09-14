class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int st=0,end= arr.size()-k;
        while(st<end){
            int mid = st + (end-st)/2;
            if(x - arr[mid] > arr[mid +k] - x){
                st = mid +1;
            }
            else{
                end = mid;
            }
        }
 return vector<int>(arr.begin() + st, arr.begin() + st + k);  
   }
};