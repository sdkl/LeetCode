The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".




思路：
找到规律后很简单
0				2n-2				4n-4				6n-6
	1		2n-3	2n-1		4n-5	4n-3		6n-7	6n-5
...
第一行和最后一行的周期是2n-2，其他各行没2个数的周期也是2n-2，中间那个数是2n-2-2*i。