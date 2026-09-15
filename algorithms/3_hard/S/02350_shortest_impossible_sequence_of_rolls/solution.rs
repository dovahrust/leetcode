impl Solution {
    pub fn shortest_sequence(rolls: Vec<i32>, k: i32) -> i32 {
        let rolls_len = rolls.len();
        let mut states = vec![0_i32; (k as usize) + 1];
        let mut state: i32 = 1;
        let mut seen_cnt: i32 = 0;

        for roll in rolls  {
            if states[roll as usize] != state {
                seen_cnt += 1;
                states[roll as usize] = state;

                if seen_cnt == k {
                    state += 1;
                    seen_cnt = 0;
                }
            }
        }

        state
    }
}
