class Solution {
public:
    char findTheDifference(string s, string t){
       char final = 0;

       for(char c:s){
        final ^=c;
       }

       for(char c:t){
        final ^=c;
       }
return  final;



    }
};