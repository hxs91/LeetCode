<<<<<<< HEAD
#LeetCode
�м����һ��д��ʱ��˼���Ƚϻ��ң�
Regular Expression Matching


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




=======
LeetCode
========
   
source code of leetcode OJ.
>>>>>>> 639e050a0bb5655ad1069ef8614e1ad2b8f247ae
