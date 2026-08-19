use std::collections::BinaryHeap;
use std::cmp::Reverse;

impl Solution {
    pub fn smallest_chair(mut times: Vec<Vec<i32>>, target_friend: i32) -> i32 {
        assert!(times.len() <= 10_000 && target_friend >= 0 && target_friend < times.len() as i32);

        let mut data: Vec<(i32, i32, i32)> = times.into_iter().enumerate().map(|(i, v)| {
            (v[0], v[1], i as i32)
        }).collect();
        data.sort_unstable_by(|a, b| a.0.cmp(&b.0));

        let mut free_chair: BinaryHeap<Reverse<i32>> = BinaryHeap::new();
        let mut used_chair: BinaryHeap<Reverse<(i32, i32)>> = BinaryHeap::new();
        let mut next_free = 0_i32;

        for (curr_start, curr_end, curr_friend) in data {
            while let Some(Reverse((end, chair))) = used_chair.peek() && *end <= curr_start {
                free_chair.push(Reverse(*chair));
                used_chair.pop();
            }

            let new_chair = match free_chair.pop() {
                Some(Reverse(chair)) => chair,
                None => {
                    next_free += 1;
                    next_free - 1
                },
            };

            if curr_friend == target_friend {
                return new_chair;
            }

            used_chair.push(Reverse((curr_end, new_chair)));
        }

        unreachable!("logic error")
    }
}
