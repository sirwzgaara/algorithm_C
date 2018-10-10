
#include <stdio.h>

void ShellSort(int *a, int N)
{
    int i, j, Increment;
    int Tmp;

    for (Increment = N / 2; Increment >= 1; Increment /= 2)
    {
        for (i = Increment; i < N; i++)
        {
            Tmp = a[i];
            for (j = i; j >= Increment; j -= Increment)
                if (Tmp < a[j - Increment])
                    a[j] = a[j - Increment];
                else
                    break;
            a[j] = Tmp;
        }
    }
}

void main()
{

}

