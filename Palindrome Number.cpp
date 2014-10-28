class Solution {
public:
	bool isPalindrome(int x) {
		if(x < 0) return false;
		int dvsNow = 1;
		while(x/dvsNow >= 10)
			dvsNow *= 10;
		while(x != 0)
		{
			int l = x/dvsNow;
			int r = x%10;
			if(l != r) return false;
			x = (x%dvsNow)/10;
			dvsNow /= 100;
		}
		return true;
	}
};