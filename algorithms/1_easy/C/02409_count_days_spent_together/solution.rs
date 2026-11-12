impl Solution {
    const NONE_LEAPS_DAYS: [i32; 12] = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];

    fn get_month_and_day(bytes: &[u8]) -> (i32, i32) {
        (
            ((bytes[0] - b'0') as i32) * 10 + (bytes[1] - b'0') as i32,
            ((bytes[3] - b'0') as i32) * 10 + (bytes[4] - b'0') as i32
        )
    }

    pub fn count_days_together(arrive_alice: String, leave_alice: String, arrive_bob: String, leave_bob: String) -> i32 {
        let aa = Self::get_month_and_day(arrive_alice.as_bytes());
        let al = Self::get_month_and_day(leave_alice.as_bytes());
        let ba = Self::get_month_and_day(arrive_bob.as_bytes());
        let bl = Self::get_month_and_day(leave_bob.as_bytes());

        let max_a = aa.max(ba);
        let min_l = al.min(bl);

        if min_l < max_a { return 0; }

        if min_l.0 == max_a.0 { return min_l.1 - max_a.1  + 1; }

        min_l.1 +
        Self::NONE_LEAPS_DAYS[max_a.0 as usize - 1] - max_a.1 + 1 +
        Self::NONE_LEAPS_DAYS[(max_a.0 as usize)..(min_l.0 as usize - 1)].into_iter().sum::<i32>()
    }
}
