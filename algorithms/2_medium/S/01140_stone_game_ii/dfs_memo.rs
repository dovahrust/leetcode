impl Solution {
    const INF: i32 = i32::MAX;

    fn dfs(piles: &[i32], idx: usize, m: usize, memo: &mut [i32]) -> i32 {
        let len = piles.len();
        if idx == len {
            return 0;
        }

        let memo_idx = idx * (len + 1) + m;
        if memo[memo_idx] != Self::INF {
            return memo[memo_idx];
        } 

        let mut sum = 0;
        let mut res = i32::MIN;
        let end = (idx + 2 * m).min(len); 
        for i in idx..end {
            sum += piles[i];
            res = res.max(sum - Self::dfs(piles, i + 1, (i - idx + 1).max(m), memo));
        }
        memo[memo_idx] = res;
        res
    }

    pub fn stone_game_ii(piles: Vec<i32>) -> i32 {
        assert!(piles.len() >= 1 && piles.len() <= 100);
        let len = piles.len();
        let mut memo = vec![Self::INF; (len + 1) * len];
        let diff = Self::dfs(&piles, 0, 1, &mut memo);
        let sum: i32 = piles.iter().sum();

        // diff = A - B
        // sum = A + B
        // (sum + diff) / 2 = (A+B + A-B)/2 = A.
        (sum + diff) / 2
    }
}
