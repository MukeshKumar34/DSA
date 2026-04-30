class Solution {
public:
    string removeOccurrences(string s, string part) {
        int pos = s.find(part);

        if(pos == string::npos) {
            return s;
        }

        s.erase(pos, part.length());

        return removeOccurrences(s, part);
    }
};