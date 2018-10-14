
#include <stdio.h>

#ifdef pseudo_code

/* 蛮力计算点对距离 */
for (i = 0; i < N; i++)
	for (j = i + 1; j < NumPointsInStrip; i++)
		if (Dist(Pi, Pj) < ans)
			ans = Dist(Pi, Pj);

for (i = 0; i < NumPointsInStrip; i++)
	for (j = i + 1; j < NumPointsInStrip; j++)
		if (Pj and Pi's coordinates differ by more than ans)
			break;
		else if (Dist(Pi, Pj) < ans)
			ans = Dist(Pi, Pj);

#endif

int main()
{
	return 1;
}

