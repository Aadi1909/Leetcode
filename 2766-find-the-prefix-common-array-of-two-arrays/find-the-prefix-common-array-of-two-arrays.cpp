class Solution {
public:
    std::vector<int> findThePrefixCommonArray(std::vector<int>& A, std::vector<int>& B) {
        std::vector<int> map(51, 0);
        std::vector<int> answer;
        answer.push_back(A[0] == B[0] ? 1 : 0);
        if(A[0] == B[0]) map[A[0]]++;
        else map[A[0]]++, map[B[0]]++;
        for(int i = 1; i < A.size(); ++i){
            if(A[i] == B[i]){
                answer.push_back(answer.back() + 1);
                if(map[A[i]] == 0) map[A[i]]++;
            }
            else {
                int x = map[A[i]];
                int y = map[B[i]];
                answer.push_back(answer.back() + x + y);
                if(map[A[i]] == 0)map[A[i]]++;
                if(map[B[i]] == 0)map[B[i]]++;
            }
        }
        return answer;
    }
};