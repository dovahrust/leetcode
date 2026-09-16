impl Solution {
    pub fn maximum_importance(n: i32, roads: Vec<Vec<i32>>) -> i64 {
        let mut deg = vec![0_i32; n as usize];
        for r in roads {
            let (u, v) = (r[0], r[1]);
            deg[u as usize] += 1;
            deg[v as usize] += 1;
        }

        deg.sort_unstable();

        let mut res: i64 = 0;
        for (i, d) in deg.into_iter().enumerate() {
            let imp = (i + 1) as i64;
            let d = d as i64;
            res += d * imp;
        }

        res
    }
}
