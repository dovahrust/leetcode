impl Solution {
    const MAX_NUM: i32 = 70;
    const MIN_NUM: i32 = 1;

    pub fn minimize_the_difference(mat: Vec<Vec<i32>>, target: i32) -> i32 {
        let rows = mat.len(); assert!(rows > 0 && rows <= 70);
        let cols = mat[0].len(); assert!(cols > 0 && cols <= 70);

        let mut max_sum = 0;
        for line in &mat {
            assert!(line.len() == cols);
            let mut max = i32::MIN;
            for &v in line {
                assert!(v >= Self::MIN_NUM && v <= Self::MAX_NUM);
                max = max.max(v);
            }
            max_sum += max;
        }

        let states_len = (max_sum + 1) as usize;
        let mut buff = vec![false; 2 * states_len];
        let (mut prev, mut curr) = buff.split_at_mut(states_len);
        prev[0] = true;

        for line in mat {
            for i in 0..states_len {
                if !prev[i] { continue; }

                for &v in &line {
                    curr[i + v as usize] = true;
                }

                prev[i] = false;
            }

            (prev, curr) = (curr, prev);
        }

        let mut min = i32::MAX;
        for i in 0..states_len {
            if prev[i] {
                min = min.min(((i as i32) - target).abs());
            }
        }

        min
    }
}
