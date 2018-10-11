
#include <stdio.h>

/* 插入排序 */
void InsertionSort(int *a, int N)
{
    int j, P, Tmp;

    /* 每趟让排序的数量增加1，即将后面的一个插入到前面的排序数组中 */
    for (P = 1; P < N; P++)
    {
        Tmp = a[P];
        for (j = P; j > 0 && a[j - 1] > Tmp; j--)
            a[j] = a[j - 1];
        a[j] = Tmp;
    }
}

void main()
{

}

