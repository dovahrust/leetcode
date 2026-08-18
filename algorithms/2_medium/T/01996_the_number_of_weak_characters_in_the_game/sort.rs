impl Solution {
    pub fn number_of_weak_characters(mut properties: Vec<Vec<i32>>) -> i32 {
        assert!(properties.len() >= 2);

        properties.sort_unstable_by(|a, b| {
            if a[0] == b[0] {
                a[1].cmp(&b[1])
            } else {
                a[0].cmp(&b[0])
            }
        });

        let mut cnt = 0_usize;
        let mut curr_max = i32::MIN;
        let mut level = properties.last().unwrap()[0];
        let mut level_max = properties.last().unwrap()[1];

        for p in properties.into_iter().rev() {
            if p[0] < level {
                curr_max = curr_max.max(level_max);
                level = p[0];
                level_max = p[1];
            }

            if p[1] < curr_max {
                cnt += 1;
            }
        }

        cnt.try_into().unwrap()
    }
}
