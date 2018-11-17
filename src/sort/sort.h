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
