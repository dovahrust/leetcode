impl Solution {
    pub fn count_groups(position: Vec<i32>, speed: Vec<i32>, distance: i32) -> i32 {
        if position.is_empty() { return 0; }

        let len = speed.len();
        let mut cnt = 1_i32;
        let mut min_speed = speed[len - 1];
        let mut prev_pos = position[len - 1];

        for i in (0..(len - 1)).rev() {
            if prev_pos - position[i] > distance && speed[i] <= min_speed {
                min_speed = speed[i];
                cnt += 1;
            }

            prev_pos = position[i];
        }

        cnt
    }
}
