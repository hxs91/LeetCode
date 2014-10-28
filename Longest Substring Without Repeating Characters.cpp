#include<iostream>
#include<string>
#include<cstdio>
#include<map>
using namespace std;

class Solution {
public:
    map<char,int> my;
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        my.clear();
        my.insert(map<char,int>::value_type(s[0],0));
        int * dp = new int[s.size()];
        int ans=1,t;
        dp[0] = 1;
        char ch;
        for(int i=1;i<s.size();i++){
            ch = s[i];
            if(my.find(ch)!=my.end()){
                t = my[ch];
                if(i-t-1 >= dp[i-1]) dp[i]=dp[i-1]+1;
                else dp[i] = i-t;
                my[ch] = i;
            }
            else{
                my.insert(map<char,int>::value_type(ch,i));
                dp[i]=dp[i-1]+1;
            }
            if(dp[i]>ans) ans = dp[i];
        }
        delete dp;
        return ans;
    }
};