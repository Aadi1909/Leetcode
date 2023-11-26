class Solution {
private:
    vector<string> foo(int n){
	if(n == 1){
		vector<string> tmp;
		tmp.push_back("0");
		tmp.push_back("1");
		return tmp;
	} 	

	vector<string> r = foo(n-1);
	vector<string> res;
	for(int i = 0; i < r.size(); i++){
		res.push_back("0" + r[i]);
	}
	for(int j = r.size()-1; j >= 0; j--){
		res.push_back("1" + r[j]);
	}	
	return res;
}
    
public:
    vector<int> grayCode(int n) {
	   /*
        vector<string> res = foo(n);
	    vector<int> decimalValues;

        for (const auto& binaryString : res) {
            bitset<32> bits(binaryString);
            int decimalValue = bits.to_ulong();
            decimalValues.push_back(decimalValue);
        }
        */
        vector<int> decimalValues;
        int num = 0;
        for(int i = 0; i < (1 << n); i++){
            num ^= (i & -i);
            decimalValues.push_back(num);
        }
        
        return decimalValues;
    }
};
