impl Solution {
    pub fn sum_game(num: String) -> bool {
        let bytes = num.as_bytes();
        let len = bytes.len();
        assert!((len & 1) == 0 && len >= 2);
        let half = len / 2;
        let (mut balance_sum, mut balance_cnt) = (0_isize, 0_isize);

        for i in 0..half {
            match bytes[i] {
                b'?' => balance_cnt += 1,
                b'0'..=b'9' => balance_sum += (bytes[i] - b'0') as isize,
                _ => unreachable!()
            }

            match bytes[i + half] {
                b'?' => balance_cnt -= 1,
                b'0'..=b'9' => balance_sum -= (bytes[i + half] - b'0') as isize,
                _ => unreachable!()
            }
        }

        if balance_cnt == 0 {
            return balance_sum != 0;
        }

        if (balance_cnt & 1) == 1 || balance_cnt * balance_sum >= 0 || (balance_sum.abs() % 9) != 0 {
            return true;
        }

        (balance_sum.abs()) / 9 != (balance_cnt.abs() / 2)
    }
}
