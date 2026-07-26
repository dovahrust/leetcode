long long flowerGame(const int n, const int m)
{
    const long long even_cnt_n = n / 2;
    const long long odd_cnt_n = n - even_cnt_n;

    const long long even_cnt_m = m / 2;
    const long long odd_cnt_m = m - even_cnt_m;

    return even_cnt_n * odd_cnt_m + odd_cnt_n * even_cnt_m;
}
