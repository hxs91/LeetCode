<<<<<<< HEAD
#LeetCode
�м����һ��д��ʱ��˼���Ƚϻ��ң�
*****Regular Expression Matching



2014.10.29
����Find Minimum in Rotated Sorted Array II �� Find Minimum in Rotated Sorted Array��������Ŀ����Ҳ�����ˡ�����������ȫһ���Ĳ�˵����Ŀ�����ر�ɵ�ơ�

Maximum Product Subarray
��̬�滮������������������ͣ������������ǳ˷�����Ҫ���Ƿ������⡣������Ҫ��¼�������Сֵ��

Reverse Words in a String
C++ʵ��ʱ�Ǹ�����ֵ��voidҲ��ʵ���������˺þ�

Subsets
DFSʵ�֣���Ȼ��WA�˺ü��Ρ�

Climbing Stairs
���ż����仯dp

2014.10.30

Merge Sorted Array
�鲢�������

Remove Duplicates from Sorted List 
�Բм���


2014.10.31

*****���챻��ĿThreeSumŰ���裬������̫�ۣ�����������ϸ����

2014.11.3

Remove Element
*****next Permutation

2014.11.4

*****Gas Station
�����ҵ��뷨�Ƚ�naive����������ģ�����������ֻ�����߶�����������Ż����ѡ���ɹ������õ����߶����ĳɶθ��£�����lazy��ǽ������������discuss���������9�д���͸㶨�����⣬��Ҳ�Ǹо����Լ������ˡ��Ⱦ�������

Swap Nodes in Pairs
�Բ�������

Sum Root to Leaf Numbers
�Բж�������

Spiral Matrix II 
��������DFS

2014.11.5

Single Number
�ֻ�����

Simplify Path
ջ������

Search a 2D Matrix 
��ά���ֲ��ң�easy

Remove Duplicates from Sorted Array
����ɢ����ʱ��д���˵Ĵ��롣����

Unique Paths �� Unique Paths II 
���ż�dp

2014.11.7

*****First Missing Positive
���⣡���constant space����������Ҫ������������һ��Сʱ���޽�����ο����˵�˼�룬�뷨���ǰ����ˣ����������

***Search for a Range
���У�Ҫ��Զ��ֲ����кܺõ���⡣

Validate Binary Search Tree 
�Բж�������

**Linked List Cycle
��һ����������ȷ�����Ƿ���ڻ���Ҫ�����ռ䣬˫ָ�룬������һ�¼��ɡ������ڻ��ض�����ֿ��ָ��������ָ�롣

Binary Tree Preorder Traversal
������ǰ�����������ʵ�֣�ջ���Բ���

2014.11.8

*Insert Interval
����+vector

**Distinct Subsequences
��̬�滮��dp[i][j]����S[i]���ж��ٸ�T[j].��ôdp[i][j]=d[i-1][j]+( S[i]==T[j]?dp[i-1][j-1]:0 );

Best Time to Buy and Sell Stock II 
�Բ�̰���⣬����͵����������ߵ��������ɡ�

*Gray Code
������

*Construct Binary Tree from Preorder and Inorder Traversal 
ͨ��ǰ�������������������

Multiply Strings
�����˷�

******Implement strStr() 
KMP
������һ���ر�򵥵Ĵ𰸣�֮���ٿ��ɣ������ַ����������ƣ���������Ҳ������o(�s���t)o��

public int strStr(String haystack, String needle) {

	for (int i = 0; ; i++) {
	
		for (int j = 0; ; j++) {
		
			if (j == needle.length()) return i;
			
			if (i + j == haystack.length()) return -1;
			
			if (needle.charAt(j) != haystack.charAt(i + j)) break;
			
		}
		
	}
	
}

***Reorder List
��һ������������˼·���Ƚ�����ֳ����Σ��ٽ������һ�η���Ȼ����������������ƴ�ӵõ����𰸡�
���磺1->2->3->4 ----> 1->2,3->4 ----> 1->2,4->3 ----> 1->4->2->3;

Candy 
������⣬�뷨���Ǻܼ��ġ�

Binary Tree Zigzag Level Order Traversal
�����������Ҳ��WA��ô��θ����ˣ���Ȼ�Ǹճ��극ͷ�Բ������𡣡���

*****Trapping Rain Water 
����ջ�Ļ�������~~~

*Flatten Binary Tree to Linked List 
��һ����������ƽ

2014.11.9

****Longest Consecutive Sequence
�ʼ�Դ���������ܶ಻��ʵ�ʲ��Ҹ��ӵ������������unordered_set�㶨�ˡ�����

Clone Graph
��ΪleetcodeΨһһ��ͼ�۵���Ŀ����ֻ��˵��������������͸��������

Restore IP Addresses
�ðɣ��Բ��⣬��ֻ��˵�����case���⣬��Ӯ��

Word Break
����DP

******Surrounded Regions 
�Ҹ�������ˣ���BFSʱ��ѡ����Ĳ����ĵط���һ�������������޷�����TLE�����������������dfs�Ļ����ᱬջ��

*****Single Number II
��������գ�����ǿ���Ƽ���

2014.11.10

***Min Stack
���ڴ濨�ļ�ֱ�������ϸ񡣡����Ҳ�

*****Sort List
nlgn���������򣬿�ʼд��һ�ݿ��ţ�ÿ��ѡȡβ���ڵ���Ϊpivot��������һ��case̫���⣬������ֻ��1,2,3�����¿����˻�̫���أ�ֱ��TLE������һ��ѡȡpivot�ķ���Ҳ���ǲ��У��Ͼ�case̫���⡣���������ǻ��������Ĺ鲢������Ž����������ֻ��˵�ҹ���

Insertion Sort List 
������д��������İ汾�ˣ�ֱ�ӽ��ϱߵĴ��뽻��ȥ�ˡ�����

Binary Tree Postorder Traversal
�����������ջʵ�֡�

Copy List with Random Pointer
���һ���������

Divide Two Integers
����������λ���㣬��λ����ı��ʲ��ǳ˷��ͳ������������������Ļ�������ֻ�ܹ�

Best Time to Buy and Sell Stock
�Բ���

Triangle 
�Բ�dp��

2014.11.12

Letter Combinations of a Phone Number
�Բ���

**Generate Parentheses
�����е�С��˼��

Search in Rotated Sorted Array
��������

Sqrt(x)
���֣���INT��ʹ��long long

Rotate Image
�Բ������ҹ�����

**3Sum Closest
���֣�O(n^2);

Add Binary
�Բ���

Merge Intervals
����ϲ�����

Anagrams
û��˼��һ����Ŀ

*****Set Matrix Zeroes
O(m+n)�Ŀռ䣬Ҳ�뵽һ�������ռ�Ľⷨ�������Ӷ��е�ߡ�����ɨ�裬����0�Ľ����к�����Ϊ2������0���ã�������ɨ�衣���Ժ���˵��

11.13

Evaluate Reverse Polish Notation
���沨��

Construct Binary Tree from Inorder and Postorder Traversal
������ͺ��򹹽�������

Combination Sum
�ݹ���ݣ����Ӷȸߵ�Ҫ���������������ɡ�

Convert Sorted Array to Binary Search Tree
����������������ƽ��ģ�ÿ��ȡ��λ����Ϊ�����ɡ�

Convert Sorted List to Binary Search Tree
���ġ�����

**Combination Sum II
�е�С��˼��

Combinations 
���ѣ����˵��֦

Count and Say
���ĵ��⣬�Զ���������Ҳ������ʽ����Ŀ������������⡣���ˣ�������˷ݴ������ϡ�����

***Decode Ways
��̬�滮���ðɣ������caseҲ����������

*********Sort Colors
ţ�ơ�������ֻ��˵��ѧϰ�ˡ�������һ�����飬�����ռ䣩

=======
LeetCode
========
   
source code of leetcode OJ.
>>>>>>> 639e050a0bb5655ad1069ef8614e1ad2b8f247ae
