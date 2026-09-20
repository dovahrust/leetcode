impl Solution {
    pub fn max_star_sum(vals: Vec<i32>, edges: Vec<Vec<i32>>, k: i32) -> i32 {
        let n = vals.len();
        let k = k as usize;
        let mut adj_positive_vals: Vec<Vec<i32>> = vec![Vec::new(); n];

        for e in edges {
            let (u, v) = (e[0], e[1]);

            if vals[v as usize] > 0 {
                adj_positive_vals[u as usize].push(vals[v as usize]);
            }

            if vals[u as usize] > 0 {
                adj_positive_vals[v as usize].push(vals[u as usize]);
            }
        }

        for row in adj_positive_vals.iter_mut() {
            row.sort_unstable_by_key(|&x| std::cmp::Reverse(x));
        }

        let mut res = i32::MIN;

        for u in 0..n {
            let sum = vals[u] + adj_positive_vals[u as usize].iter().take(k).sum::<i32>();
            res = res.max(sum);
        }

        res
    }
}
