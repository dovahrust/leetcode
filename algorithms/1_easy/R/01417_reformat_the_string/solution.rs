impl Solution {
    #[inline(always)]
    fn fix(
        bytes: &mut [u8],
        mut start_dig: usize,
        mut start_alph: usize,
    ) {
        let len = bytes.len();
        while start_dig < len && start_alph < len {
            while start_dig < len && bytes[start_dig] >= b'0' && bytes[start_dig] <= b'9' {
                start_dig += 2;
            }

            while start_alph < len && bytes[start_alph] >= b'a' && bytes[start_alph] <= b'z' {
                start_alph += 2;
            }

            if start_dig < len && start_alph < len {
                let tmp = bytes[start_dig];
                bytes[start_dig] = bytes[start_alph];
                bytes[start_alph] = tmp;
                start_dig += 2;
                start_alph += 2;
            }
        }
    }

    pub fn reformat(s: String) -> String {
        if s.len() <= 1 { return s; }

        let mut bytes = s.into_bytes();
        let len = bytes.len();
        let mut cnt_dig = 0_isize;
        let mut cnt_alph = 0_isize;

        for &b in &bytes {
            match b {
                b'0'..=b'9' => cnt_dig += 1,
                b'a'..=b'z' => cnt_alph += 1,
                _ => unreachable!("invalid input")
            }
        }

        if (cnt_dig - cnt_alph).abs() > 1 {
            return String::new();
        }

        if cnt_dig > cnt_alph {
            Self::fix(&mut bytes, 0, 1);
        } else {
            Self::fix(&mut bytes, 1, 0);
        }

        String::from_utf8(bytes).unwrap()
    }
}
