
#include <stdio.h>

#ifdef persudo_code

/* 最小生成树的Prim算法 */
void Prim(Table T)
{
    Vertex V, W;

    for (;;)
    {
        V = smallest unknown distance vertex;
        if (V == NotAVertex)
            break;
        for each W adjacnet to V
            if (!T[W].Known)
                /* 这个判断条件和dijkstra算法不同，不用考虑历史路径长度 */
                if (Cvw < T[W].Dist)
                {
                    Decrease(T[W].Dist to Cvw);
                    T[W].Path = V:
                }
    }
}

/* 最小生成树的Kruskal算法，最坏时间O(ElogE) */
void Kruskal(Graph G)
{
    int EdgeAccepted;
    DisjSet S;
    PriorityQueue H;
    Vertex U, V;
    SetType Uset, Vset;
    Edge E;

    /* 将顶点存入到不相交集中 */
    Initialize(S);
    /* 将图中每条边读入优先队列中 */
    ReadGraphIntoHeapArray(G, H);
    BuildHeap(H);

    EdgeAccepted = 0;
    while (EdgeAccepted < NumVertex - 1)
    {
        /* 从优先队列中找最小的边，U和V是这个边的两个顶点 */
        E = DeleteMin(H);
        Vset = Find(U, S);
        Uset = Find(V, S);
        /* 若两个顶点不在一个集合中，那么说明有一个顶点不在树种，合并，否则已经在了，继续找
         * 下一个最小的边*/
        if (Uset != Vset)
        {
            EdgeAccepted++;
            SetUnion(S, Uset, Vset);
        }
    }
}

#endif

void main()
{

}

