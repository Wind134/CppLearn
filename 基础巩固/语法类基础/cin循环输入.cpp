#include <iostream>
int main ()
{
	int currVal = 0, val = 0;
	if (std::cin >> currVal){
		int cnt = 1;
		while (std::cin >> val){	// 在Windows端Ctrl Z结束这个循环
			if (val == currVal)	++cnt;
			else {
				std::cout << currVal << " occurs "
					<< cnt << " times " << std::endl;
				currVal = val;
				cnt = 1;
			}
			if (std::cin.get() == '\n')	break;	// 如果不想通过Ctrl Z可以加这么一行
		}
		std::cout << currVal << " occurs "
			<< cnt << " times " << std::endl;
	}
	return 0;
}
