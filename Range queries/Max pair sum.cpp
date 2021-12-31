

#include <iostream>
#include <utility>
#include <algorithm>
#include <climits>
using namespace std;
struct node
{
    int max_sum;
    int sum;
    int bps;
    int bss;
};

node query(node *tree, int start, int end, int treeNode, int left, int right)
{

    // Completely out
    if (left > end || right < start)
    {
        node ans;
        ans.max_sum = -100000;
        ans.sum = -100000;
        ans.bps = -100000;
        ans.bss = -100000;
        return ans;
    }

    // Completely inside
    if (start >= left && end <= right)
    {
        return tree[treeNode];
    }

    // Partially inside
    int mid = (start + end) / 2;

    node l = query(tree, start, mid, 2 * treeNode, left, right);
    node r = query(tree, mid + 1, end, 2 * treeNode + 1, left, right);
    node result;

    result.sum = l.sum + r.sum;
    result.bps = max(l.bps, l.sum + r.bps);
    result.bss = max(r.bss, l.bss + r.sum);
    result.max_sum = max(max(max(l.max_sum, r.max_sum), max(l.sum + r.bps, r.sum + l.bss)), l.bss + r.bps);

    return result;
}

void create(int *arr, node *tree, int start, int end, int treeNode)
{
    if (end == start)
    {
        tree[treeNode].max_sum = arr[start];
        tree[treeNode].sum = arr[start];
        tree[treeNode].bps = arr[start];
        tree[treeNode].bss = arr[start];
        return;
    }

    int mid = (start + end) / 2;

    create(arr, tree, start, mid, 2 * treeNode);
    create(arr, tree, mid + 1, end, 2 * treeNode + 1);

    tree[treeNode].sum = tree[2 * treeNode].sum + tree[2 * treeNode + 1].sum;
    tree[treeNode].bps = max(tree[2 * treeNode].bps, tree[2 * treeNode].sum + tree[2 * treeNode + 1].bps);
    tree[treeNode].bss = max(tree[2 * treeNode + 1].bss, tree[2 * treeNode].bss + tree[2 * treeNode + 1].sum);
    tree[treeNode].max_sum = max(max(max(tree[2 * treeNode].max_sum, tree[2 * treeNode + 1].max_sum), max(tree[2 * treeNode].sum + tree[2 * treeNode + 1].bps, tree[2 * treeNode + 1].sum + tree[2 * treeNode].bss)), tree[2 * treeNode].bss + tree[2 * treeNode + 1].bps);

    return;
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    int q;
    cin >> q;
    node *tree = new node[4 * n];
    create(arr, tree, 0, n - 1, 1);
    while (q--)
    {

        int b, c;
        cin >> b >> c;
        cout << query(tree, 0, n - 1, 1, b - 1, c - 1).max_sum << endl;
    }

    return 0;
}