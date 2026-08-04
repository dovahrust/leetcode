impl Solution {
    pub fn stone_game_iii(stone_value: Vec<i32>) -> String {
        let len = stone_value.len();
        let (mut next1, mut next2, mut next3) = (0_i32, 0_i32, 0_i32);

        for i in (0..len).rev() {
            let mut curr = stone_value[i] - next1;
            if i + 1 < len {
                curr = curr.max(stone_value[i] + stone_value[i + 1] - next2);
            }
            if i + 2 < len {
                curr = curr.max(stone_value[i] + stone_value[i + 1] + stone_value[i + 2] - next3);
            }
            (next1, next2, next3) = (curr, next1, next2);
        }

        match next1.cmp(&0) {
            std::cmp::Ordering::Less => "Bob".to_string(),
            std::cmp::Ordering::Equal => "Tie".to_string(),
            std::cmp::Ordering::Greater => "Alice".to_string(),
        }
    }
}
