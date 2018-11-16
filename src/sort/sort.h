/* insert sort */
void insertion_sort(int a[], unsigned int n)
{
    unsigned int j, p;
    int tmp;
    //a[0] = minData
    a[0] = 1;
    for( p = 2; p <= n; p++)
    {
        tmp = a[p];
        for(j = p; tmp < a[j-1]; j--)
            a[j] = a[j-1];
        a[j] = tmp;
    }
}
