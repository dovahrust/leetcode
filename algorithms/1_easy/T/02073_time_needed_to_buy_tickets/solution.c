int timeRequiredToBuy(const int *restrict tickets, const int tickets_len, const int k) {
    const int t_kth = tickets[k];
    int wait_time = 0;
    for (int i = 0; i < tickets_len; i += 1) {
        wait_time += MIN(tickets[i], t_kth - (i > k ? 1 : 0));
    }
    return wait_time;
}
