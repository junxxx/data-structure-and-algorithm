/* insert sort */
#define LeftChild(i) (2 * (i) + 1)
#define Cutoff (3)

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

/**
 *  Lpos = start of left half, Rpos = start of right half
 */
void merge(ElementType A[], ElementType TmpArray[], int Lpos, int Rpos, int RightEnd)
{
    int i, LeftEnd, NumElements, TmpPos;

    LeftEnd = Rpos - 1;
    TmpPos = Lpos;
    NumElements = RightEnd - Lpos + 1;

    /* main loop */
    while (Lpos <= LeftEnd && Rpos <= RightEnd)
    {
        if (A[Lpos] <= A[Rpos])
            TmpArray[TmpPos++] = A[Lpos++];
        else
            TmpArray[TmpPos++] = A[Rpos++];
    }
    while (Lpos <= LeftEnd)     /* Copy rest of first half */
        TmpArray[TmpPos++] = A[Lpos++];
    while (Rpos <= RightEnd)    /* Copy rest of second half */
        TmpArray[TmpPos++] = A[Rpos++];

    /* Copy TmpArray back */
    for( i = 0; i < NumElements; i++, RightEnd--)
        A[RightEnd] = TmpArray[RightEnd];
}

void m_sort(ElementType A[], ElementType TmpArray[], int Left, int Right)
{
    int Center;
    if (Left < Right)
    {
        Center = (Left + Right) / 2;
        m_sort(A, TmpArray, Left, Center);
        m_sort(A, TmpArray, Center + 1, Right);
        merge(A, TmpArray, Left, Center + 1, Right);
    }
}

void merge_sort(ElementType A[], int N)
{
    ElementType *TmpArray;

    TmpArray = malloc(N * sizeof(ElementType));
    if (TmpArray != NULL)
    {
        m_sort(A, TmpArray, 0, N - 1);
        free(TmpArray);
    }
    else
        FatalError("No space for tmp array!!!");
}

/* Return median of left, center, and right */
/* Order these and hide the pivot */
ElementType median3(ElementType A[], int left , int right)
{
    int center = (left + right) / 2;

    if (A[left] > A[center])
        swap(&A[left], &A[center]);
    if (A[left] > A[right])
        swap(&A[left], &A[right]);
    if (A[center] > A[right])
        swap(&A[center], &A[right]);

    /* Invariant: A[left] <= A[center] <= A[right] */
    
    swap(&A[center], &A[right - 1]);    /* hide pivot */
    return A[right - 1];                /* return pivot */
}

void q_sort(ElementType A[], int left, int right)
{
    int i, j;
    ElementType pivot;

    if (left + Cutoff <= right)
    {
        pivot = median3(A, left , right);
        i = left, j = right - 1;
        for (; ; )
        {
            while (A[++i] < pivot) {}
            while (A[--j] > pivot) {}
            if ( i < j)
                swap(&A[i], &A[j]);
            else
                break;
        }
        swap(&A[i], &A[right - 1]);     /* restore pivot */

        q_sort(A, left, i - 1);
        q_sort(A, i + 1, right);
    }
    else                                /* Do an insertion sort on the subarray */
        insertion_sort(A, right - left + 1);
}
void quick_sort(ElementType A[], int N)
{
    q_sort(A, 0, N - 1);
}

