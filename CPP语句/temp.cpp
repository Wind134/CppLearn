#include <iostream>
using namespace std;

int main()
{
	int data1, data2;
	cin >> data1 >> data2;
	if (data1 != data2)
		throw runtime_error("Data must refer to same ISBN");
	cout << data1 + data2 << endl;
	while (cin >> data1 >> data2)
	{
		try {
		if (data1 != data2)	throw runtime_error("Data must refer to same ISBN");
		}
		catch (runtime_error err) {
			cout << err.what()
				<< "\nTry Again? Enter y or n" << endl;
			char c;
			cin >> c;
			if (!cin || c == 'n')	break;	//跳出while循环
		}
	}


	
	

}
