impl Solution {
    pub fn time_required_to_buy(tickets: Vec<i32>, k: i32) -> i32 {
        let k = k as usize;
        let t_kth = tickets[k];
        let mut wait_time: i32 = 0;
        for (i, t) in tickets.into_iter().enumerate() {
            wait_time += t.min(t_kth - if i > k { 1 } else { 0 });
        }
        wait_time
    }
}
