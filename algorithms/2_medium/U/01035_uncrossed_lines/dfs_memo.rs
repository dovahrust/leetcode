impl Solution {
    fn dfs(n1: &[i32], n1_idx: usize, n2: &[i32], n2_idx: usize, memo: &mut [i32]) -> i32 {
        let (n1_len, n2_len) = (n1.len(), n2.len());
        if n1_idx == n1_len || n2_idx == n2_len {
            return 0;
        }
        let memo_idx = n1_idx * n2_len + n2_idx;
        if memo[memo_idx] != -1 {
            return memo[memo_idx];
        }

        let mut res = 0_i32;
        if n1[n1_idx] == n2[n2_idx] {
            res = 1 + Self::dfs(n1, n1_idx + 1, n2, n2_idx + 1, memo);
        }
        res = res.max(Self::dfs(n1, n1_idx + 1, n2, n2_idx, memo));
        res = res.max(Self::dfs(n1, n1_idx, n2, n2_idx + 1, memo));

        memo[memo_idx] = res;
        res
    }

    pub fn max_uncrossed_lines(nums1: Vec<i32>, nums2: Vec<i32>) -> i32 {
        let (len1, len2) = (nums1.len(), nums2.len());
        assert!(len1 >= 1 && len1 <= 500 && len2 >= 1 && len2 <= 500);
        let mut memo = vec![-1_i32; len1 * len2];

        Self::dfs(&nums1, 0, &nums2, 0, &mut memo)
    }
}
