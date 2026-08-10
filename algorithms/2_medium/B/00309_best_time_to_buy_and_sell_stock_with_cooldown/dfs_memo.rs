impl Solution {
    fn dfs(prices: &[i32], idx: usize, buy: usize, memo: &mut [[i32; 2]]) -> i32 {
        let len = prices.len();
        if len <= idx {
            return 0;
        }

        if memo[idx][buy] != - 1 { 
            return memo[idx][buy];
        }

        let mut res = 0;
        if buy == 1 {
            res = res.max(Self::dfs(prices, idx + 1, 0, memo) - prices[idx]);
            res = res.max(Self::dfs(prices, idx + 1, 1, memo));
        } else {
            res = res.max(Self::dfs(prices, idx + 2, 1, memo) + prices[idx]);
            res = res.max(Self::dfs(prices, idx + 1, 0, memo));
        }

        memo[idx][buy] = res;
        res
    }

    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let len = prices.len();
        assert!(len <= 5000 && len >= 1);
        assert!(prices.iter().all(|&x| x >= 0 && x <= 1000));

        let mut memo = vec![[-1_i32, -1_i32]; len];

        Self::dfs(&prices, 0, 1, &mut memo)
    }
}
