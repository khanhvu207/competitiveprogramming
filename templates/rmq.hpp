void init(int* A)
{
    for (int i = 1; i <= n; ++i)
        rmq[0][i] = A[i];
    for (int i = 1; (1 << i) <= n; ++i)
        for (int j = 1; j + (1 << i) - 1 <= n; ++j)
            rmq[i][j] = max(rmq[i - 1][j], rmq[i - 1][j + (1 << (i - 1))]);
}

int get(int L, int R)
{
    int k = log2(R - L + 1);
    return max(rmq[k][L], rmq[k][R - (1 << k) + 1]);
}