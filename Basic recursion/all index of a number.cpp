
int allIndexes(int input[], int size, int x, int output[])
{
    /* Don't write main().
       Don't read input, it is passed as function argument.
       Save all the indexes in the output array passed and return the size of output array.
       Taking input and printing output is handled automatically.

    */
    static int j = 0;
    static int i = -1;
    if (size == 0)
    {
        return j;
    }

    i++;
    if (input[0] == x)
    {
        output[j] = i;
        j++;
    }

    int ans = allIndexes(input + 1, size - 1, x, output);

    return ans;
}
