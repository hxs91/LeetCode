class Solution {
public:
    string convert(string s, int nRows) {
        int len = s.size(),i,j,part,pc;
        string x="";
        if(len==0 || nRows==1) return s;
        part = nRows*2-2;
        pc = len / part + 1;
        for(i=0;i<nRows;i++){
            for(j=0;j<pc;j++){
                if(i==0){
                    if(j*part<len)  x.push_back(s[ j*part ]);
                }
                else if(i==nRows-1){
                    if(j*part + i < len) x.push_back(s[ j*part + i ]);
                }
                else{
                    if(j*part + i < len) x.push_back(s[ j*part + i]);
                    if(j*part + part-i < len) x.push_back(s[ j*part + part-i ]);
                }
            }
        }
        return x;
    }
};