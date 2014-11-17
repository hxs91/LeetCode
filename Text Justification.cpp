class Solution {
public:
    vector<string> ans;

    vector<string> fullJustify(vector<string> &words, int L) {
        int len=words.size();
        int tot,i,j,k,t,tmp;
        string one;
        for(i=0;i<len;){
            tot=0;
            one="";
            for(j=i;j<len;j++){
                tmp = tot+j-i+words[j].size();
                if( tmp>L ){
                    break;
                }
                else{
                    tot+=words[j].size();
                }
            }
            int slot_cnt,slots=L-tot;
            if(j==i+1){
                one.append(words[i]);
                for(k=0;k<slots;k++) one.push_back(' ');
            }
            else if(j==len){
                for(k=i;k<j;k++){
                    one.append(words[k]);
                    one.push_back(' ');
                    slots--;
                    if(k==j-1)
                        while(slots>0) one.push_back(' '),slots--;
                }
            }
            else{
                slot_cnt=j-i-1;
                int left=slots/slot_cnt;
                int lefto=slots%slot_cnt;
                for(k=i;k<j;k++){
                    if(k==i) one.append(words[k]);
                    else{
                        for(t=0;t<left;t++) one.push_back(' ');
                        if( lefto>0 ){
                            one.push_back(' ');
                            lefto--;
                        }
                        one.append(words[k]);
                    }
                }
            }
            i=j;
            ans.push_back(one);
        }
        return ans;
    }
};