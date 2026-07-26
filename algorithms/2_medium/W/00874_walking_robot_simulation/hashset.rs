use std::collections::HashSet;

impl Solution {
    const DIR_LEN: usize = 4;
    const DIRECTIONS: [(i32, i32); Self::DIR_LEN] = [(0, 1), (1, 0), (0, -1), (-1, 0)];

    pub fn robot_sim(commands: Vec<i32>, obstacles: Vec<Vec<i32>>) -> i32 {
        assert!(obstacles.iter().all(|o| o.len() == 2));
        let mut set: HashSet<(i32, i32)> = obstacles.into_iter().map(|o|(o[0], o[1])).collect();
        let (mut x, mut y) = (0_i32, 0_i32);
        let mut dir_idx = 0_usize;
        let mut max = 0;
        for c in commands {
            match c {
                -2 => dir_idx = (dir_idx + Self::DIR_LEN - 1) % Self::DIR_LEN,
                -1 => dir_idx = (dir_idx + 1) % Self::DIR_LEN,
                1..=9 => {
                    let (dx, dy) = Self::DIRECTIONS[dir_idx];
                    for _ in 1..=c {
                        if set.contains(&(x + dx, y + dy)) {
                            break;
                        }
                        x += dx;
                        y += dy;
                        max = max.max(x * x + y * y);
                    }
                },
                _ => unreachable!("invalid input"),
            }
        }

        max
    }
}
