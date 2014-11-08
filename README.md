<<<<<<< HEAD
#LeetCode
有几题第一次写的时候思绪比较混乱：
Regular Expression Matching


2014.10.29
对于Find Minimum in Rotated Sorted Array II 和 Find Minimum in Rotated Sorted Array这两道题目，我也是醉了。。。代码完全一样的不说，题目还都特别傻逼。

Maximum Product Subarray
动态规划，类似于求最大连续和，但这里由于是乘法，还要考虑符号问题。于是需要记录最大与最小值。

Reverse Words in a String
C++实现时那个返回值是void也着实让我困惑了好久

Subsets
DFS实现，竟然还WA了好几次。

Climbing Stairs
入门级记忆化dp

2014.10.30

Merge Sorted Array
归并排序基础

Remove Duplicates from Sorted List 
脑残简单题


2014.10.31

*****今天被题目ThreeSum虐出翔，打了球太累，过几天再仔细看。

2014.11.3

Remove Element
*****next Permutation

2014.11.4

*****Gas Station
此题我的想法比较naive，基本就是模拟最笨的做法，只是用线段树对其进行优化而已。完成过程中用到了线段树的成段更新，利用lazy标记解决，不过看了discuss里，有人用了9行代码就搞定了这题，我也是感觉被自己蠢死了。先就这样吧

Swap Nodes in Pairs
脑残链表题

Sum Root to Leaf Numbers
脑残二叉树题

Spiral Matrix II 
回旋矩阵，DFS

2014.11.5

Single Number
抑或运算

Simplify Path
栈的运用

Search a 2D Matrix 
二维二分查找，easy

Remove Duplicates from Sorted Array
做离散化的时候都写烂了的代码。。。

Unique Paths 和 Unique Paths II 
入门级dp

2014.11.7

*****First Missing Positive
好题！这个constant space的限制真是要人命啊，想了一个小时毫无结果，参考别人的思想，想法真是棒极了，完美解决。

***Search for a Range
还行，要求对二分查找有很好的理解。

Validate Binary Search Tree 
脑残二叉树题

**Linked List Cycle
在一个单链表中确定其是否存在环，要求常数空间，双指针，步伐不一致即可。若存在环必定会出现快的指针撵上慢指针。

Binary Tree Preorder Traversal
二叉树前序遍历，迭代实现，栈，脑残题

2014.11.8

*Insert Interval
二分+vector

**Distinct Subsequences
动态规划，dp[i][j]代表S[i]中有多少个T[j].那么dp[i][j]=d[i-1][j]+( S[i]==T[j]?dp[i-1][j-1]:0 );

Best Time to Buy and Sell Stock II 
脑残贪心题，在最低点买进，在最高点卖出即可。

*Gray Code
格雷码

*Construct Binary Tree from Preorder and Inorder Traversal 
通过前序和中序遍历构造二叉树

Multiply Strings
大数乘法

******Implement strStr() 
KMP
解锁了一个特别简单的答案，之后再看吧，反正字符串我是弱逼，估计现在也看不懂o(╯□╰)o：

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
