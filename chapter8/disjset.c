
#include <stdio.h>

#define NumSets   128

typedef int DisjSet[NumSets + 1];
typedef int SetType;
typedef int ElementType;

void Initialize(DisjSet S);
void SetUnion(DisjSet S, SetType Root1, SetType Root2);
SetType Find(ElementType X, DisjSet S);

/* 隐式的树，值为0表示自己是根，初始的时候，每个元素都是根 */
void Initialize(DisjSet S)
{
    int i;

    for (i = NumSets; i > 0; i--)
        S[i] = 0;
}

/* 合并，将Root2的根设置为Root1 */
void SetUnion(DisjSet S, SetType Root1, SetType Root2)
{
    S[Root2] = Root1;
}

/* 查找根，递归直到值为0，就找到了一个根，返回在数组中的位置 */
SetType Find(ElementType X, DisjSet S)
{
    if (S[X] <= 0)
        return X;
    else
        return Find(S[X], S);
}

void main()
{

}

