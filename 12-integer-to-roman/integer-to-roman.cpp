class Solution {
public:
    string intToRoman(int num) {
        string s = "";
        process(s, '*', '*', 'M', num / 1000);
        num = num % 1000;
        process(s, 'M', 'D', 'C', num / 100);
        num = num % 100;
        process(s, 'C', 'L', 'X', num / 10);
        num = num % 10;
        process(s, 'X', 'V', 'I', num);

        return s;
    }

    void process(string &s, char major, char middle, char minor, int val){
        if(val <= 3){
            for(int i = 1; i <= val; i++){
                s.push_back(minor);
            }
        }
        else if(val == 4){
            s.push_back(minor);
            s.push_back(middle);
        }
        else if(val == 5){
            s.push_back(middle);
        }
        else if(val <= 8){
            s.push_back(middle);
            for(int i = 6; i <= val; i++){
                s.push_back(minor);
            }
        }
        else if(val == 9){
            s.push_back(minor);
            s.push_back(major);
        }
    }
};