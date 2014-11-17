struct node{
    int len,hei;
    node(){}
    node(int l,int h):len(l),hei(h){}
};

class Solution {
public:
    vector<vector<int> > hori;
    vector<vector<int> > vert;
    vector<vector<node> > rcd;

    int Min(int a,int b){
        return a<b?a:b;
    }

    int maximalRectangle(vector<vector<char> > &matrix) {
        int m=matrix.size();
        if(m==0) return 0;
        int n=matrix[0].size();
        if(n==0) return 0;
        hori.assign(m+1,vector<int>(n+1,0));
        vert.assign(m+1,vector<int>(n+1,0));
        rcd.assign(m+1,vector<node>(n+1,node(0,0)));
        int i,j;
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                if( matrix[i-1][j-1]=='1' ){
                    hori[i][j]=hori[i][j-1]+1;
                    vert[i][j]=vert[i-1][j]+1;
                }
            }
        }
        node up,left;
        int ans=0;
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                if( matrix[i-1][j-1]=='1' ){
                    up=rcd[i-1][j];
                    left=rcd[i][j-1];
                    if(up.hei==0 && left.hei==0){
                        rcd[i][j]=node(1,1);
                    }
                    else if( up.hei==0 ){
                        rcd[i][j]=node(hori[i][j],1);
                    }
                    else if(left.hei==0){
                        rcd[i][j]=node(1,vert[i][j]);
                    }
                    else{
                        int l=Min(hori[i][j],up.len);
                        int h=Min(vert[i][j],left.hei);
                        if( l*(up.hei+1) > h*(left.len+1) ){
                            rcd[i][j]=node(l,up.hei+1);
                        }
                        else{
                            rcd[i][j]=node(left.len+1,h);
                        }
                    }
                    if( rcd[i][j].hei*rcd[i][j].len > ans ){
                        ans = rcd[i][j].hei*rcd[i][j].len;
                    }
                }
            }
        }
        return ans;
    }
};