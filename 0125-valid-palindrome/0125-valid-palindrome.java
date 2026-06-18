class Solution {
    public boolean isPalindrome(String s) {
       s=s.toLowerCase();
     String  ss = s.replaceAll("[^a-z0-9]","");
       String sr = new StringBuilder(ss).reverse().toString();
       if(ss.equals(sr)){
        return true;
       }
return false;
    }
}