
#include <stdio.h>
#include <stdlib.h>

/* 合并两个排序数组，注意这两个数组是连续的，lpos是第一个数组开始的位置，rpos是第二个
 * 数组开始的位置，rightend是第二个数组结束的位置，第一个数组在rpos - 1位置结束 */
void Merge(int *a, int *tmpa, int lpos, int rpos, int rightend)
{
    int i, leftend, numelements, tmppos;

    leftend = rpos - 1;
    tmppos = lpos;
    numelements = rightend - lpos + 1;

    /* 合并两个排序数组的方法 */
    while (lpos <= leftend && rpos <= rightend)
    {
        if (a[lpos] < a[rpos])
            tmpa[tmppos++] = a[lpos++];
        else
            tmpa[tmppos++] = a[rpos++];
    }

    /* 处理剩余部分 */
    while (lpos <= leftend)
        tmpa[tmppos++] = a[lpos++];
    while (rpos <= rightend)
        tmpa[tmppos++] = a[rpos++];

    /* 将数组拷贝回a中 */
    for (i = lpos; i < numelements; i++, rightend--)
        a[rightend] = tmpa[rightend];
}

/* 递归核心例程，将tmpa作为参数传递，这样不用在递归的每个阶段都分配内存 */
void MSort(int *a, int *tmpa, int left, int right)
{
    int center;

    if (left < right)
    {
        center = (left + right) / 2;
        MSort(a, tmpa, left, center);
        MSort(a, tmpa, center + 1, right);
        Merge(a, tmpa, left, center + 1, right);
    }
}

/* 归并排序外部接口 */
void MergeSort(int *a, int N)
{
    int *tmpa;
    tmpa = malloc(N * sizeof(int));

    MSort(a, tmpa, 0, N - 1);
    free(tmpa);
}

void main()
{

}

