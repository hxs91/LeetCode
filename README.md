<<<<<<< HEAD
#LeetCode
有几题第一次写的时候思绪比较混乱：
*****Regular Expression Matching



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

***Reorder List
将一个链表重排序，思路：先将链表分成两段，再将后边那一段反序，然后将这两个新链表交叉拼接得到最后答案。
例如：1->2->3->4 ----> 1->2,3->4 ----> 1->2,4->3 ----> 1->4->2->3;

Candy 
理解题意，想法还是很简答的。

Binary Tree Zigzag Level Order Traversal
对于这个题我也能WA那么多次给跪了，果然是刚吃完饭头脑不清晰吗。。。

*****Trapping Rain Water 
单调栈的基本运用~~~

*Flatten Binary Tree to Linked List 
将一个二叉树碾平

2014.11.9

****Longest Consecutive Sequence
最开始脑袋里边闪过很多不切实际并且复杂的做法，最后用unordered_set搞定了。。。

Clone Graph
作为leetcode唯一一个图论的题目，我只能说，这题真是无聊透顶。。。

Restore IP Addresses
好吧，脑残题，我只能说这个多case的题，你赢了

Word Break
暴力DP

******Surrounded Regions 
我给此题跪了，在BFS时，选择更改操作的地方不一样，导致了我无法理解的TLE。。。另外如果采用dfs的话，会爆栈。

*****Single Number II
此题棒棒哒！！！强烈推荐啊

2014.11.10

***Min Stack
对内存卡的简直不能再严格。。。我擦

*****Sort List
nlgn的链表排序，开始写了一份快排，每次选取尾部节点作为pivot，但由于一组case太特殊，所有数只有1,2,3，导致快排退化太严重，直接TLE，换了一种选取pivot的方法也还是不行，毕竟case太特殊。。。。于是换了链表版的归并排序这才解决。。。我只能说我跪了

Insertion Sort List 
就懒得写插入排序的版本了，直接将上边的代码交上去了。。。

Binary Tree Postorder Traversal
后序遍历，用栈实现。

Copy List with Random Pointer
深拷贝一个随机链表

Divide Two Integers
看到有人用位运算，移位运算的本质不是乘法和除法吗，如果解答就是这个的话，那我只能跪。

Best Time to Buy and Sell Stock
脑残题

Triangle 
脑残dp题

2014.11.12

Letter Combinations of a Phone Number
脑残题

**Generate Parentheses
还是有点小意思的

Search in Rotated Sorted Array
二分搜索

Sqrt(x)
二分，爆INT，使用long long

Rotate Image
脑残数组找规律题

**3Sum Closest
二分，O(n^2);

Add Binary
脑残题

Merge Intervals
排序合并区间

Anagrams
没意思的一个题目

*****Set Matrix Zeroes
O(m+n)的空间，也想到一个常数空间的解法，但复杂度有点高。就是扫描，遇到0的将其行和列置为2（遇到0不置），继续扫描。。以后再说吧

11.13

Evaluate Reverse Polish Notation
简单逆波兰

Construct Binary Tree from Inorder and Postorder Traversal
从中序和后序构建二叉树

Combination Sum
递归回溯，复杂度高得要死。。。就这样吧。

Convert Sorted Array to Binary Search Tree
构建二叉排序树，平衡的，每次取中位数作为根即可。

Convert Sorted List to Binary Search Tree
无聊。。。

**Combination Sum II
有点小意思。

Combinations 
爆搜，加了点剪枝

Count and Say
无聊的题，对读法的描述也不够形式，题目理解至今有问题。算了，随便找了份代码贴上。。。

***Decode Ways
动态规划，好吧，此题的case也是让人醉了

*********Sort Colors
牛逼。。。我只能说我学习了。（遍历一遍数组，常数空间）

=======
LeetCode
========
   
source code of leetcode OJ.
>>>>>>> 639e050a0bb5655ad1069ef8614e1ad2b8f247ae
