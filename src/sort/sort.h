/* insert sort */
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
