class Solution {
public:
    string reverseWords(string s) {
        //for first spaces
        int idx=-1;
        int i=0;
        while(true){
            if(s[i]!=' ') break;
            else idx++,i++;
        }
        if(idx!=-1) s.erase(0,idx+1);

        //for last spaces
        int j=s.length()-1;
        int idx2=s.length()-1;
        while(true){
            if(s[j]!=' ')break;
            else idx2--, j--;
        }
        if(idx2!=s.length()-1) s.erase(idx2+1, s.length());

        //for middle space 
        bool lastCharSpace = false;
    size_t writeIndex = 0;
    for (size_t readIndex = 0; readIndex < s.length(); ++readIndex) {
        if (s[readIndex] == ' ') {
            if (!lastCharSpace) {
                s[writeIndex++] = ' ';
                lastCharSpace = true;
            }
        } else {
            s[writeIndex++] = s[readIndex];
            lastCharSpace = false;
        }
    }
    s.resize(writeIndex);
        reverse(s.begin(),s.end());
        //my string is perfect for removal for reversing

        int low=0,ff=s.find(' ');
        int hi=ff-1;
        bool lst=false;
        while(hi<s.length()-1){
    	    int l=low,h=hi;
    	    while(l<=h){
    		    swap(s[l],s[h]);
    		    l++,h--;
    	    }
    	    low=ff+1;
    	    ff=s.find(' ',low);
    	    if(ff==-1){
    		    hi=s.length()-1;
    	    }
    	    else{
    		    hi=ff-1;
    	    }
        }
        hi=s.length()-1;
        while(low<=hi){
    	    swap(s[low],s[hi]);
    	    low++,hi--;
        }
        return s;
    }
};