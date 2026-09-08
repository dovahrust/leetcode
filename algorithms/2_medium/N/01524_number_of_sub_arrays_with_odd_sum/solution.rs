impl Solution {
    const MOD: i32 = 1_000_000_007;

    pub fn num_of_subarrays(arr: Vec<i32>) -> i32 {
        let mut cnt = 0_i32;
        let mut odd = 0_i32;
        let mut even = 1_i32;
        let mut sum = 0_i32;

        for a in arr {
            sum += a;

            if (sum & 1) == 1 {
                cnt = (cnt + even) % Self::MOD;
                odd += 1;
            } else {
                cnt = (cnt + odd) % Self::MOD;
                even += 1;
            }
        }

        cnt
    }
}
