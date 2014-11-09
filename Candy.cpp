class Solution {
public:
    int candy(vector<int> &ratings) {
        int len=ratings.size();
        if(len==0) return 0;
        if(len==1) return 1;
        vector<int> tmp(len+2,0);
        vector<int> Candy(len+2,0);
        tmp[0]=INT_MAX;
        tmp[len+1]=INT_MAX;
        for(int i=0;i<len;i++) tmp[i+1]=ratings[i];
        for(int i=1;i<=len;i++){
            if( tmp[i]==tmp[i-1] && tmp[i]==tmp[i+1] ) Candy[i]=1;
            else if(tmp[i]<tmp[i-1] && tmp[i]==tmp[i+1]) Candy[i]=1;
            else if(tmp[i]<tmp[i+1] && tmp[i]==tmp[i-1]) Candy[i]=1;
            else if(tmp[i]<tmp[i-1] && tmp[i]<tmp[i+1]) Candy[i]=1;
        }
        int j;
        for(int i=1;i<=len;i++){
            if(Candy[i]==1){
                j=i+1;
                while(j<=len&&tmp[j]>tmp[i]){
                    if(Candy[i]+1>Candy[j]) Candy[j]=Candy[i]+1;
                    j++;
                    i++;
                }
            }
        }
        for(int i=len;i>=1;i--){
            if(Candy[i]==1){
                j=i-1;
                while(j>=1&&tmp[j]>tmp[i]){
                    if(Candy[i]+1>Candy[j]) Candy[j]=Candy[i]+1;
                    j--;
                    i--;
                }
            }
        }
        int ans=0;
        for(int i=1;i<=len;i++){
            //cout<<Candy[i]<<" ";
            ans+=Candy[i];
        }
        //cout<<endl;
        return ans;
    }
};