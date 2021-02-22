#include <stdio.h>

// 최빈수 구하기 

int main()
{
	int case_count;

	scanf("%d", &case_count);

	for (int i = 0; i < case_count; i++)
	{
		int n;
		int max_count = 0;
		int answer = 0;
		int num[101] = { 0 };
		scanf("%d", &n);

		for (int k = 0; k < 1000; k++)
		{
			int temp;
			scanf("%d", &temp);
			num[temp]++;
		}

		for (int k = 0; k < 101; k++)
		{
			if (max_count <= num[k])
			{
				max_count = num[k];
				answer = k;
			}
		}

		printf("#%d %d\n", n, answer);
	}

	return 0;
}