
#include <stdio.h>

#define cutoff   3

static void Swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/* 取3个数的中值，并移动到right - 1的位置，因为right已经在比枢纽元大的位置上了 */
int Median3(int *a, int left, int right)
{
    int center = (left + right) / 2;

    /* 效果是，a[left] <= a[center] <= a[right] */
    if (a[left] > a[center])
        Swap(&a[left], &a[center]);
    if (a[left] > a[right])
        Swap(&a[left], &a[right]);
    if (a[center] > a[right])
        Swap(&a[center], &a[right]);

    /* 将枢纽元移动到right - 1的位置上并返回枢纽元的值 */
    Swap(&a[center], &a[right - 1]);
    return a[right - 1];
}

/* 快速排序递归核心例程 */
void QSort(int *a, int left, int right)
{
    int i, j;
    int Pivot;

    if (left + cutoff <= right)
    {
        /* 获取枢纽元 */
        Pivot = Median3(a, left, right);
        i = left, j = right - 1;

        for (;;)
        {
            /* 这里必须这样处理，否则若i，j两个位置的元素和枢纽元相等，那么死循环
                这样写保证了每次先移动i和j */
            while (a[++i] < Pivot);
            while (a[--j] > Pivot);
            if (i < j)
                Swap(&a[i], &a[j]);
            else
                break;
        }
        Swap(&a[i], &a[right - 1]);

        /* 处理左右两边 */
        QSort(a, left, i - 1);
        QSort(a, i + 1, right);
    }
    else
    {
    //只有不到3个元素，用插入排序，其实可以放大比例，比如1000个元素以内使用插入排序
    }
}

/* 快速排序外部接口 */
void QuickSort(int *a, int N)
{
    QSort(a, 0, N - 1);
}

/* 快速选择问题主例程，选择第k小的 */
void Qselect(int *a, int k, int left, int right)
{
    int i, j;
    int Pivot;

    if (left + cutoff <= right)
    {
        Pivot = Median3(a, left, right);;
        i = left, j = right - 1;

        for (;;)
        {
            while (a[++i] < Pivot);
            while (a[--j] > Pivot);
            if (i < j)
                Swap(&a[i], &a[j]);
            else
                break;
        }
        Swap(&a[i], &a[right - 1]);

        /* 这里和快速排序不同，因为只需要处理一个子问题 */
        if (k <= i)
            Qselect(a, k, left, i - 1);
        else if (k > i + 1)
            Qselect(a, k, i + 1, right);
    }
}

void main()
{

}

