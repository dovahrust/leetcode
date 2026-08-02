impl Solution {
    pub fn even_odd_bit(mut n: i32) -> Vec<i32> {
        assert!(n >= 0);
        let mut odd = 0_i32;
        let mut even = 0_i32;
        let mut is_odd = true;

        while n > 0 {
            if (n & 1) == 1 {
                if is_odd {
                    odd += 1;
                } else {
                    even += 1;
                }
            }

            is_odd = !is_odd;
            n >>= 1;
        }

        vec![odd, even]
    }
}
