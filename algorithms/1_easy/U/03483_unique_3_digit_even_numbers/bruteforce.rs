impl Solution {
    const FREQS_LEN: usize = 10;
    const MAX_3DIG: usize = 999;
    const MIN_3DIG: usize = 100;
    const TBALE_LEN: usize = (Self::MAX_3DIG - Self::MIN_3DIG + 1) >> 1; // for even nums

    pub fn total_numbers(digits: Vec<i32>) -> i32 {
        let mut freqs = [0_u32; Self::FREQS_LEN];
        for d in digits {
            assert!(d >= 0 && (d as usize) < Self::FREQS_LEN);
            freqs[d as usize] += 1;
        }

        let mut seen = [false; Self::TBALE_LEN];
        let mut cnt = 0_i32;

        for i in 1..Self::FREQS_LEN {
            if freqs[i] == 0 { continue; }

            freqs[i] -= 1;

            for j in 0..Self::FREQS_LEN {
                if freqs[j] == 0 { continue; }

                freqs[j] -= 1;

                let base = i * 100 + j * 10;

                for k in (0..Self::FREQS_LEN).step_by(2) {
                    if freqs[k] > 0 && !seen[(base + k - Self::MIN_3DIG) >> 1] {
                        seen[(base + k - Self::MIN_3DIG) >> 1] = true;
                        cnt += 1;
                    }
                }

                freqs[j] += 1;
            }

            freqs[i] += 1;
        }

        cnt
    }
}
