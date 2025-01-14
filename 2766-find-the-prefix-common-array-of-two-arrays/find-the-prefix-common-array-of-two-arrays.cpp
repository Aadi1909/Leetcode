class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        set<int> setA, setB;
        vector<int> answer(A.size(), 0);
        for(int i = 0; i < A.size(); ++i){
            set<int> intersection;
            setA.insert(A[i]);
            setB.insert(B[i]);
            set_intersection(setA.begin(), setA.end(), setB.begin(), setB.end(),
                            inserter(intersection, intersection.begin()));
            answer[i] = intersection.size();
        }
        return answer;
    }
};