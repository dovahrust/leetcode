impl Solution {
    pub fn maximum_sale_items(items: Vec<Vec<i32>>, budget: i32) -> i32 {
        debug_assert!(budget >= 1 && budget<= 1500);
        debug_assert!(items.iter().all(|x| x[0] >= 1 && x[0] <= 1500));

        let budget = budget as usize;
        let max_factor = items.iter().map(|x| x[0]).max().unwrap() as usize;
        let mut buff = vec![0_i32;  max_factor + 1 + budget + 1];
        let (mut cnts, mut dp) = buff.split_at_mut(1 + max_factor);

        for item in &items { cnts[item[0] as usize] += 1; }

        for i in 1..=max_factor {
            let mut sum: i32 = 0;
            for j in (i..=max_factor).step_by(i) {
                sum += cnts[j];
            }
            cnts[i] = sum;
        }

        for item in items {
            let (factor, price) = (item[0] as usize, item[1] as usize);

            if price > budget { continue; }

            for i in price..=budget { dp[i] = dp[i].max(dp[i - price] + 1); }

            let cnt = cnts[factor];

            if cnt == 1 { continue; }

            for i in (price..=budget).rev() {
                dp[i] = dp[i].max(dp[i - price] + cnt);
            }
        }

        dp[budget]
    }
}
