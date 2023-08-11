/*
- 这个例子可以看到，catch负责捕捉与他相邻的try作用域内发生的错误信息
	-- 这是一个简单的展示
*/
#include <iostream>
#include <limits>
using namespace std;

int main()
{
	int data1, data2;
	while (cin >> data1 >> data2)
	{
		try {
			// if (cin.fail())	throw runtime_error("Invalid input");

			if (data1 != data2)	throw runtime_error("Data must be same.");
			else cout << "The sum: " << data1 + data2 << endl;
		}
		catch (runtime_error err) {
			cout << err.what()
				<< "\nTry Again? Enter y or n" << endl;
			char c;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清空输入缓冲区
			cin >> c;
			if (!cin || c == 'n')	break;	//跳出while循环
		}
	}
}

