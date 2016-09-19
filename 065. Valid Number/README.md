Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.


“ +-.e0123456789”
	cout << s.isNumber("0") << endl;
	cout << s.isNumber(" 0.1 ") << endl;
	cout << s.isNumber("2e10") << endl;
	cout << s.isNumber(".1") << endl;
	cout << s.isNumber(" -54.53061") << endl;
	cout << s.isNumber("abc") << endl;
	cout << s.isNumber("1 a") << endl;
	cout << s.isNumber("e") << endl;
	cout << s.isNumber("0e") << endl;
	cout << s.isNumber(".") << endl;
	cout << s.isNumber(" ") << endl;
	cout << s.isNumber(". 1") << endl;
	cout << s.isNumber("5+1") << endl;
	cout << s.isNumber("6e6.5") << endl;

提交了很多次才通过，有很多情况没考虑到的。