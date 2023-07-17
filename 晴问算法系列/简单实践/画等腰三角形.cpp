#include <stdio.h>
int main()
{
	int nums;
	printf("请输入等腰三角形的边长：");
	scanf("%d", &nums);
	for (int i = 1; i <= nums ; i++)
	{
		for (int j = 1; j <= 2 * nums - 1 ; j++)
		{
			if (i != nums)
			{
				if (j  ==  (nums - i + 1) || (2 * nums  - j) == (nums - i + 1))	printf("*");
				else printf(" ");
			}
			else
			{
				if (j % 2 != 0)	printf("*");
				else printf (" ");
			}
		}
		printf("\n");
	}	
	return 0;
}
