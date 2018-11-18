/* insert sort */
#define LeftChild(i) (2 * (i) + 1)
typedef int ElementType;
void insertion_sort(int a[], unsigned int n)
{
    unsigned int j, p;
    int tmp;
    for( p = 1; p < n; p++)
    {
        tmp = a[p];
        for(j = p; j > 0 && tmp < a[j-1]; j--)
            a[j] = a[j-1];
        a[j] = tmp;
    }
}

/* shell sort */
void shell_sort(int a[], int n)
{
    int i, j ,incremnt;
    int tmp;
    for (incremnt = n / 2; incremnt > 0; incremnt /= 2)
    {
        for ( i = incremnt; i < n; i++)
        {
            tmp = a[i];
            for ( j = i; j >= incremnt; j-= incremnt)
            {
                if (tmp < a[j - incremnt])
                    a[j] = a[j - incremnt];
                else
                    break;
            }
            a[j] = tmp;
        }
    }
}

void perc_down(ElementType A[], int i, int N)
{
    int Child;
    ElementType Tmp;

    for (Tmp = A[i]; LeftChild(i) < N; i = Child)
    {
        Child = LeftChild(i);
        if (Child != N - 1 && A[Child +1] > A[Child])
            Child++;
        if (Tmp < A[Child])
            A[i] = A[Child];
        else
            break;
    }
    A[i] = Tmp;
}

void heap_sort(ElementType A[], int N)
{
    int i;

    for( i = N / 2; i >= 0; i--) /* build heap */
        perc_down(A, i, N);
    for (i = N - 1; i > 0; i--)
    {
        swap(&A[0], &A[i]);     /* Delete max*/
        perc_down(A, 0, i);
    }
}
