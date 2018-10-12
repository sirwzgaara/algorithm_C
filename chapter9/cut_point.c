
#include <stdio.h>

#ifdef persudo_code

/* 深度优先遍历分配编号 */
void AssignNum(Vertex V)
{
    Vertex W;
    Num[V] = Counter++;
    Visited[V] = True;
    for each W adjacent to V
        if (!Visited[W])
        {
            Parent[W] = V;
            AssignNum(W);
        }
}

/* 分配Low值 */
void AssignLow(Vertex V)
{
    Vertex W;
    
    /* rule1，直接选Num[W]，后面再比较 */
    Low[V] = Num[W];
    for each W adjacent to V
    {
        if (Num[W] > Num[V])
        {
            AssignLow(W);
            if (Low[W] >= Num[V])
                printf("%v is a articulation point", V);
            /* rule3，正向边的最小值 */
            Low[V] = Min(Low[V], Low[W]);
        }
        else if (Parent[V] != W)
            /* rule2，背向边的最小值 */
            Low[V] = Min(Low[V], Num[W]);
    }
}

/* 整合先序和后序两个流程 */
void FindArt(Vertex V)
{
    Vertex W;

    Visited[V] = True;
    Low[V] = Num[W] = Counter++;
    for each W adjacent to V
    {
        if (!Visited[W])
        {
            Parent[W] = V;
            FindArt(W);
            if (Low[W] >= Num[V])
                printf("%v is an articulation point\n", V);
            Low[V] = Min(Low[V], Low[W]);
        }
        else if (Parent[V] != W)
            Low[W] = Min(Low[V], Num[W]);
    }
}

#endif

void main()
{

}

