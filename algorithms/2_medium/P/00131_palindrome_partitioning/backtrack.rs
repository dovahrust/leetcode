impl Solution {
    #[inline(always)]
    fn is_palindrome(bytes: &[u8]) -> bool {
        if bytes.len() <= 1 { return true; }

        let mut hi = bytes.len() - 1;
        let mut lo = 0_usize;

        while lo < hi {
            if bytes[lo] != bytes[hi] {
                return false;
            }

            lo += 1;
            hi -= 1;
        }

        true
    }

    fn backtrack<'a>(bytes: &'a [u8], lo: usize, res: &mut Vec<Vec<String>>, tmp: &mut Vec<&'a [u8]>) {
        let len = bytes.len();

        if lo >= len {
            res.push(tmp.iter().map(|&x| String::from_utf8_lossy(x).into_owned()).collect::<Vec<_>>());
            return;
        }

        for hi in lo..len {
            if Self::is_palindrome(&bytes[lo..=hi]) {
                tmp.push(&bytes[lo..=hi]);
                Self::backtrack(bytes, hi + 1, res, tmp);
                tmp.pop();
            }
        }
    }

    pub fn partition(s: String) -> Vec<Vec<String>> {
        let mut res: Vec<Vec<String>> = Vec::default();
        let mut tmp: Vec<&[u8]> = Vec::with_capacity(s.len());

        Self::backtrack(s.as_bytes(), 0, &mut res, &mut tmp);

        res
    }
}
