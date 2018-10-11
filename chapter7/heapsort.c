
#include <stdio.h>

/* 标准二叉堆有一个哑头，数据部分下标从1开始，排序时是从0开始的，要做下处理 */
#define LeftChild(i) (2 * (i) + 1)

/* 交换两个值 */
void Swap(int * a, int * b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/* 将位置i的节点下滤 */
void PercDown(int *a, int i, int N)
{
    int Child, tmp;
    for (tmp = a[i]; LeftChild(i) < N; i = Child)
    {
        Child = LeftChild(i);
        if (Child != N - 1 && a[Child + 1] > a[Child])
            Child++;

        if (tmp < a[Child])
            a[i] = a[Child];
        else
            break;
    }
    a[i] = tmp;
}

/* 堆排序外部接口，这里使用的是最小堆，因此数组是降序排序的 */
void HeapSort(int *a, int N)
{
    int i;

    /* 在原始数组上下滤建堆 */
    for (i = N / 2; i > 0; i--)
        PercDown(a, i, N);

    /* 将a[0]和a[i]交换，这样数组从后面开始就是排序的，此时a[0]不满足堆序，下滤调整 */
    for (i = N - 1; i > 0; i--)
    {
        Swap(&a[0], &a[i]);
        PercDown(a, 0, i);
    }
}

void main()
{

}

