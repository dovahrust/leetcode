impl Solution {
    const INF: i32 = i32::MAX;

    pub fn nearest_valid_point(x: i32, y: i32, points: Vec<Vec<i32>>) -> i32 {
        debug_assert!(x >= 1 && x <= 10_000 && y >= 1 && y <= 10_000);
        let mut min_dis = Self::INF;
        let mut min_dis_idx = -1_isize;

        for (i, p) in points.iter().enumerate() {
            debug_assert!(p.len() == 2);
            let (px, py) = (p[0], p[1]);
            debug_assert!(px >= 1 && px <= 10_000 && py >= 1 && py <= 10_000);
            if px == x || py == y {
                let curr_dis = (x - px).abs() + (y - py).abs();
                if curr_dis < min_dis {
                    min_dis = curr_dis;
                    min_dis_idx = i as isize;
                }
            }
        }

        min_dis_idx.try_into().unwrap()
    }
}
