class Solution {
public:
long long int binarysearch(int num){
    int s=0;
    int e = num;
   long long  int mid = s + (e-s)/2;
    int ans = -1;
      while(s<=e){
        if(mid * mid >num){
            e=mid-1;
        }
        else if (mid * mid <num){
            ans = mid;
            s = mid + 1;
        }
        else{
            return mid;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

    int mySqrt(int x) {
        return binarysearch(x);
    }
};