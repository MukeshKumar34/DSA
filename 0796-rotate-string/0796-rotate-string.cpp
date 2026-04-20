class Solution {
public:
    bool rotateString(string s, string goal) {
  if(s.length()!= goal.length()){
    return 0;
  }
  string hello = s + s;
  return hello.find(goal) != string ::npos;
    }
};