Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.


思路：
主要考虑各种特殊输入
1.非数字字符
2.空字符
3.负数
4.比INT_MAX还大，或比INT_MIN小的数

追加：
5.“+1”正数符号
6."    +010"空格
7.小数
8."  -0012a42"输出要为-12？
9."   +0 123"输出为0
10."2147483648"大于INT_MAX的输出INT_Max