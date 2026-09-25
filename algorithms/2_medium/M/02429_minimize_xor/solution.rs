impl Solution {
    pub fn minimize_xor(num1: i32, num2: i32) -> i32 {
        assert!(num1 >= 1 && num2 >= 1);
        let (num1, num2) = (num1 as u32, num2 as u32);
        let mut ones = num2.count_ones();
        let mut res: u32 = 0;

        for i in (0..32_u32).rev() {
            if ones == 0 { break; }

            let mask: u32 = (1 << i);
            if (mask & num1) != 0 {
                res |= mask;
                ones -= 1;
            }
        }

        for i in 0..32_u32 {
            if ones == 0 { break; }

            let mask: u32 = (1 << i);
            if (mask & num1) == 0 {
                res |= mask;
                ones -= 1;
            }
        }

        res as i32
    }
}
