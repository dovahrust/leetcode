impl Solution {
    fn dfs(u: i32, bytes: &[u8], adj: &[Vec<i32>], longest: &mut i32) -> i32 {
        let mut max1: i32 = 0;
        let mut max2: i32 = 0;

        for &v in &adj[u as usize] {
            let val = Self::dfs(v, bytes, adj, longest);
            if bytes[u as usize] != bytes[v as usize] {
                if val > max1 {
                    max2 = max1;
                    max1 = val;
                } else {
                    max2 = max2.max(val);
                }
            }
        }

        *longest = (*longest).max(max1 + 1 + max2);

        max1 + 1
    }

    pub fn longest_path(parent: Vec<i32>, s: String) -> i32 {
        let mut adj: Vec<Vec<i32>> = vec![Vec::new(); parent.len()];
        for (i, p) in parent.into_iter().enumerate().skip(1) {
            adj[p as usize].push(i as i32);
        }
        let mut longest: i32 = 0;
        Self::dfs(0, s.as_bytes(), &adj, &mut longest);
        longest
    }
}
