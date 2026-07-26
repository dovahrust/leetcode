impl Solution {
    pub fn flower_game(n: i32, m: i32) -> i64 {
        let even_cnt_n = (n as i64) / 2;
        let odd_cnt_n = (n as i64) - even_cnt_n;

        let even_cnt_m = (m as i64) / 2;
        let odd_cnt_m = (m as i64) - even_cnt_m;

        even_cnt_n * odd_cnt_m + odd_cnt_n * even_cnt_m
    }
}
