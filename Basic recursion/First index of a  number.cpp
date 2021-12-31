int firstIndex(int input[], int size, int x)
{
    /* Don't write main().
       Don't read input, it is passed as function argument.
       Return output and don't print it.
       Taking input and printing output is handled automatically.


    */
    static int i = -1;
    if (size == 0)
    {
        return -1;
    }
    i++;
    if (input[0] == x)
    {
        return i;
    }

    int ans = firstIndex(input + 1, size - 1, x);
    return ans;
}
