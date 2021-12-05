
long long getInversions(long long *arr, int n)
{

  return mergesort(arr, 0, n - 1);
}

long long mergesort(long long arr[], int s, int e)
{
  long long count = 0;
  if (e > s)
  {

    int mid = s + (e - s) / 2;

    count += mergesort(arr, s, mid);
    count += mergesort(arr, mid + 1, e);

    count += merge(arr, s, mid + 1, e);
  }

  return count;
}

long long merge(long long arr[], int s, int mid, int e)
{

  int i = s;

  int j = mid;
  int k = 0;
  long long temp[e - s + 1];
  long long reflect = 0;

  while (i < mid && j <= e)
  {
    if (arr[i] <= arr[j])
    {
      temp[k] = arr[i];
      i++;
    }

    else
    {
      temp[k] = arr[j];
      j++;
      reflect += mid - i;
    }
    k++;
  }

  while (i < mid)
  {
    temp[k++] = arr[i++];
  }

  while (j <= e)
  {
    temp[k++] = arr[j++];
  }

  for (int i = s, k = 0; i <= e; i++, k++)
  {

    arr[i] = temp[k];
  }

  return reflect;
}
