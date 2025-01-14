class Solution {
public:
    std::string largestNumber(std::vector<int>& nums) {
        std::string answer;
        std::vector<std::string> a;
        for(auto& num : nums){
            a.push_back(to_string(num));
        }
        sort(a.begin(), a.end(), [](auto& x, auto& y){
            return (x + y) > (y + x);
        });
        if(a[0] == "0") return "0";
        for(auto& i : a){
            answer += i;
        }
        return answer;
    }
};