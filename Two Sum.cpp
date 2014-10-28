#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int idx(vector<int> &s,int key){
        int len=s.size();
        int l=0,r=len-1,mid;
        while(l<=r){
            mid = (l+r)>>1;
            if(s[mid] == key) return mid;
            else if(s[mid]<key) l=mid+1;
            else r = mid-1;
        }
        return -1;
    }

    int get(vector<int> & r,int key,int flag){
        int i;
        for(i=0;i<r.size();i++){
            if(r[i]==key) {
                if(flag == 0) return i+1;
                flag = 0;
            }
        }
    }

    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> tmp = numbers;
        vector<int> ans;
        int t;
        sort(numbers.begin(),numbers.end());
        for(int i=0;i<numbers.size();i++){
            t = idx(numbers,target-numbers[i]);
            if(t!=-1 && t!=i ){
                int a=get(tmp,numbers[i],0);
                int b=get(tmp,numbers[t],numbers[i]==numbers[t]);
                if(b>a) ans.push_back(a),ans.push_back(b);
                else ans.push_back(b),ans.push_back(a);
                break;
            }
        }
        return ans;
    }
};