
#*的多少代表此题的有意思程度


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


******next Permutation
STL的实现在<STL源码剖析>里可以看到


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

{
public int strStr(String haystack, String needle) {

	for (int i = 0; ; i++) {
	
		for (int j = 0; ; j++) {
		
			if (j == needle.length()) return i;
			
			if (i + j == haystack.length()) return -1;
			
			if (needle.charAt(j) != haystack.charAt(i + j)) break;
			
		}
		
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

11.14

Word Ladder
简单宽度优先搜索

*******Word Ladder II
给此题跪了，在经历了WA,RE,TLE,OLE后，终于AC了。。。OLE的原因竟然在于我没有清零。。。思路是：宽搜，记录路径

Search Insert Position
二分

Spiral Matrix
无聊题

Jump Game
简单贪心

******Jump Game II
我的想法比较笨拙，discuss里有更漂亮的解法，留待以后来看吧。

11.15

Merge Two Sorted Lists
合并两个有序链表，easy

******Minimum Window Substring
还是蛮有意思的

*****Linked List Cycle II
好题哦~~

Partition List
对于这种题，其实一般给一个空的头结点之类的比较好，会少很多判断，算了。。

********Wildcard Matching
此题同Regular Expression Matching一样都还需要好好琢磨！！！！！！

***Subsets II 
有重复元素的子集生成

******Substring with Concatenation of All Words
还不错的一题，虽然AC了，但我的代码运行了1200ms+，discuss里有人的代码只运行了198ms。。。此题还有待继续学习。

Reverse Linked List II
这种链表的题目的确是没意思了。。

*****Scramble String
还是不错的题，我的想法很简单，观察到如果字符串a能够转换到字符串b，那么a紧靠左边的x个字符一定会与b紧靠左边或者紧靠右边的x个字符相同，只是顺序不一样而已，判断他们是不是都使用了相同的字符，只需要取出两个字符串的这x个字符，排序，一个接一个比较即可。

Symmetric Tree
特瞄的这么简单一题我还以为是难题呢。。。

Populating Next Right Pointers in Each Node
BFS搞定

Search in Rotated Sorted Array II
此题与Search in Rotated Sorted Array并无什么不同。。。特喵的

Populating Next Right Pointers in Each Node II
这题代码与Populating Next Right Pointers in Each Node 都是一模一样的。。。不知道出题人的用意，我看tag好像他们要的解法是dfs？不明所以。。

Remove Duplicates from Sorted Array II
无聊的题目

***Remove Duplicates from Sorted List II
可以做一做。

11.16

**N-Queens
N皇后

N-Queens II
...不说什么了，还以为多难的题，一直不敢下手。。。

******4Sum
我的解法太臃肿了，，，应该还有更好的做法！以后看！

Valid Sudoku
无聊题

*Sudoku Solver
回溯

Permutations
考虑到了重复情况，虽然题目没有要求

Palindrome Partitioning
无聊题

11.17

Permutations II
和Permutations一样的代码，因为当时就考虑到重复的情况了

***Max Points on a Line
复杂度挺高的，数据太弱而已。能想到的优化方法也只是使用unordered_map并且不在每一次for循环时clear，那样的复杂度也有O(n^2)，不知道有没有其他的做法，另外，注意多point坐标一样的情况啊！。

***Palindrome Partitioning II
DP，这是别人的一份代码，思路和我一样，但聪明地使用了一个pal[i][j]数组来记录s[i...j]是否为回文。学习

***Valid Number
恩。。此题就是一个不断根据结果修复bug的典型代表，我挂了四次，分别是："46.e3" "+.8" ".e1" "."
以后可以再做一下，力求让代码更加精简。。。

****Permutation Sequence
做出此题也是感觉棒棒哒~~发现规律就可解了

Integer to Roman和Roman to Integer
对罗马数字无爱

****Unique Binary Search Trees II
哈哈，1A此题的感觉还是很爽的。也是对卡特兰数的理解吧

***Word Break II
动态规划+回溯

****Maximal Rectangle
O(n^2)，不知还有更好的解法没

****Longest Valid Parentheses
栈+DP。
rcd[i]表示在i之前匹配合法的最长子串的长度，将所有不合法匹配的位置都存储下来。
在计算rcd[i]时，如果栈为空，则rcd[i]=i+1;
否则栈不为空，则rcd[i]=Max(rcd[ x.top().rst ],i-x.top().rst);

*****Largest Rectangle in Histogram
单调栈的巧妙运用~~叼啊

**Text Justification
类似于word文档的”两端对齐“的功能

*******Best Time to Buy and Sell Stock III
此题，目前不会，先贴份代码吧。。。因为这是最后一道了，最近都在刷题，都没看论文，做这种无聊的事情又不能毕业，可是就是有强迫症啊，想把题都刷掉，于是就狂刷。现在是2014.11.17，我总算刷到了最后一道。。。想了好久还是都不会= =!，先贴份代码，我会在明年找工作之前将自己标星号的题都重新写一遍，并尽量将代码写得漂亮一些~今天就先这样吧，也为这疯狂的半个月划上个句号。明天开始好好干正事了。。。
