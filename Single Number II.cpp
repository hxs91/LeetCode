class Solution {
public:
    int singleNumber(int A[], int n) {
        int cnt[32] = {0};
        int result = 0;
        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < n; j++) {
                if ((A[j] >> i) & 1) {
                    cnt[i]++;
                }
            }
            result |= ((cnt[i] % 3) << i);
        }
        return result;
    }
};