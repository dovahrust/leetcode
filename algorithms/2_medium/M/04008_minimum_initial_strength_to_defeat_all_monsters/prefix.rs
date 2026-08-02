impl Solution {
    pub fn min_initial_strength(monsters: Vec<i32>, boosts: Vec<Vec<i32>>) -> i64 {
        let monsters_len = monsters.len();
        let mut prefix = vec![0_i64; monsters_len + 1];
        for b in boosts {
            assert!(b.len() == 3);
            let (l, r, v) = (b[0], b[1], b[2]);
            assert!(l >= 0 && r >= l && v >= 0);
            let (l, r) = (l as usize, r as usize);
            assert!(r < monsters_len);
            prefix[l] += v as i64;
            prefix[r + 1] -= v as i64;
        }
        prefix.pop();
        for i in 1..monsters_len {
            prefix[i] += prefix[i - 1];
        }

        let mut idx = monsters_len as isize - 1;
        while idx >= 0 && prefix[idx as usize] >= monsters[idx as usize] as i64 {
            idx -= 1;
        }

        let mut curr = 0_i64;
        if idx >= 0 {
            curr += monsters[idx as usize] as i64 - prefix[idx as usize];
            idx -= 1;
        }
        while idx >= 0 {
            curr += monsters[idx as usize] as i64;
            idx -= 1;
        }
        curr
    }
}
