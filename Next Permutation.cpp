//STL的next_permutation算法思路大致如下
//首先，从最尾端开始往前寻找两个相邻元素，令第一元素为*i，第二元素为*ii，满足 *i < //*ii。再从尾端开始找出第一个大于*i的元素，令为*j，将i，j元素对调，再将包括ii之后的元素逆序即可。
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        next_permutation(num.begin(),num.end());
    }
};
