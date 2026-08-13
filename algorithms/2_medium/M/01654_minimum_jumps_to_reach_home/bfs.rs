use std::collections::VecDeque;

const MAX_ALLOWED: i32 = 2_000;

impl Solution {
    pub fn minimum_jumps(forbidden: Vec<i32>, a: i32, b: i32, x: i32) -> i32 {
        assert!(x >= 0 && a >= 1 && b >= 1 && a <= MAX_ALLOWED && b <= MAX_ALLOWED && x <= MAX_ALLOWED);

        if x == 0 { return 0; }

        let seen_len = if a >= b {
            x + b + 1
        } else {
            let max = *forbidden.iter().max().unwrap();
            max.max(x) + a + b + 1
        };

        let mut seen = vec![(false, false); seen_len as usize];

        for f in forbidden {
            assert!(f >= 1 && f != x);
            if f < seen_len {
                seen[f as usize] = (true, true);
            }
        }

        let mut q: VecDeque<(i16, bool)> = VecDeque::new();
        q.push_back((0, false));
        seen[0] = (true, true);
        let mut turns = 0;

        while !q.is_empty() {
            let curr_len = q.len();
            for _ in 0..curr_len  {
                let (pos, can_back_jump) = q.pop_front().unwrap();
                let pos = pos as i32;

                if pos == x {
                    return turns;
                }

                if pos + a < seen_len && !seen[(pos + a) as usize].0 {
                    seen[(pos + a) as usize] = (true, true);
                    q.push_back(((pos + a) as i16, true));
                }

                if can_back_jump && pos - b > 0 && !seen[(pos - b) as usize].1 {
                    seen[(pos - b) as usize].1 = true;
                    q.push_back(((pos - b) as i16, false));
                } 
            }

            turns += 1;
        }

        -1
    }
}
