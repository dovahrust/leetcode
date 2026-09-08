impl Solution {
    const MOD: i32 = 1_000_000_007;

    pub fn number_of_unique_good_subsequences(binary: String) -> i32 {
        let (mut end_zero, mut end_one) = (0_i32, 0_i32);
        let mut has_zero = false;

        for &b in binary.as_bytes() {
            match b {
                b'0' => {
                    has_zero = true;
                    end_zero = (end_zero + end_one) % Self::MOD;
                },
                b'1' => {
                    end_one = (end_zero + end_one + 1) % Self::MOD;
                },
                _ => unreachable!()
            }
        }

        match has_zero {
            true => (end_zero + end_one + 1) % Self::MOD,
            false => end_one
        }
    }
}
