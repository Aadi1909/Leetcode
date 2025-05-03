class Solution {
public:
  vector<string> restoreIpAddresses(string s) {
    set<string> result;
    generateIPs(s, result);
    vector<string> answer(result.begin(), result.end());
    return answer;
  }

  bool isValidSegment(const string &segment) {
    if (segment.empty() || segment.size() > 3) return false;
    if (segment.size() > 1 && segment[0] == '0') return false;
    int num = stoi(segment);
    return num >= 0 && num <= 255;
}

void generateIPs(const string &s, set<string> &result) {
    int n = s.length();
    if (n < 4 || n > 12) return;
    
    for (int i = 1; i < n && i <= 3; ++i) {
        for (int j = i + 1; j < n && j - i <= 3; ++j) {
            for (int k = j + 1; k < n && k - j <= 3; ++k) {
                string seg1 = s.substr(0, i);
                string seg2 = s.substr(i, j - i);
                string seg3 = s.substr(j, k - j);
                string seg4 = s.substr(k);
                
                if (isValidSegment(seg1) && isValidSegment(seg2) && 
                    isValidSegment(seg3) && isValidSegment(seg4)) {
                    result.insert(seg1 + "." + seg2 + "." + seg3 + "." + seg4);
                }
            }
        }
    }
  }
};