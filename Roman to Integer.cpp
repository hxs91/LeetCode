class Solution {
public:
    int romanToInt(string s) {
    int i, len = s.length(), res = 0;
    int int_array[len];
    for (i = 0; i < len; i++) {
        switch (s[i]) {
        case 'I':
            int_array[i] = 1; break;
        case 'V':
            int_array[i] = 5; break;
        case 'X':
            int_array[i] = 10; break;
        case 'L':
            int_array[i] = 50; break;
        case 'C':
            int_array[i] = 100; break;
        case 'D':
            int_array[i] = 500; break;
        case 'M':
            int_array[i] = 1000; break;
        }
    }
    for (i = 0; i < len; i++) {
        if (i + 1 < len && int_array[i] < int_array[i + 1]) {
            int_array[i] = -int_array[i];
        }
        res += int_array[i];
    }
    return res;
}
};