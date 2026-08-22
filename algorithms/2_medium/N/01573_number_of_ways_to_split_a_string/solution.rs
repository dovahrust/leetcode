impl Solution {
    const MOD: usize = 1_000_000_007;

    pub fn num_ways(s: String) -> i32 {
        if s.len() <= 2 { return 0; }

        let ones: usize = s.as_bytes().iter().filter(|&&x| x == b'1').count();

        if ones == 0 {
            let n = s.len() - 2;
            return ((n * (n + 1) / 2) % Self::MOD) as i32;
        }

        if ones % 3 != 0 {
            return 0;
        }

        let spot1 = ones / 3;
        let spot2 = spot1 * 2;
        let mut curr_ones = 0_usize;
        let mut cnt1 = 0_usize;
        let mut cnt2 = 0_usize;

        for &byte in s.as_bytes() {
            match byte {
                b'1' => {
                    curr_ones += 1;
                    if curr_ones > spot2 {
                        break;
                    }
                },
                _ => {
                    if curr_ones == spot1 {
                        cnt1 += 1; 
                    } else if curr_ones == spot2 {
                        cnt2 += 1;
                    }
                }
            }
        }

        (((cnt1 + 1) * (cnt2 + 1)) % Self::MOD) as i32
    }
}
