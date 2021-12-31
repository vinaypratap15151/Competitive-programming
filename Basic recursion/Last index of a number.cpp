int lastIndex(int input[], int size, int x)
{
    /* Don't write main().
       Don't read input, it is passed as function argument.
       Return output and don't print it.
       Taking input and printing output is handled automatically.
    */
    static int ans = -1;
    static int i = -1;
    if (size == 0)
    {
        return ans;
    }

    i++;
    if (input[0] == x)
    {
        ans = i;
    }

    int res = lastIndex(input + 1, size - 1, x);

    return res;
}
