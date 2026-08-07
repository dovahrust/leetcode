impl Solution {
    fn dfs(n: u8, k: &mut i32, res: &mut Vec<u8>, seen: u16) {
        if *k == 0 {
            return;
        }

        if seen == (1_u16 << n) - 1_u16 {
            *k -= 1;
            return;
        }

        for i in 1..=n {
            let mask = 1_u16 << (i - 1);
            if mask & seen == 0 {
                res.push(i + b'0');
                Self::dfs(n, k, res, seen | mask);
                if *k == 0 {
                    return;
                }
                res.pop();
            }
        }
    }

    pub fn get_permutation(n: i32, mut k: i32) -> String {
        assert!(n <= 9 && n >= 1 && k >= 1);
        let mut res: Vec<u8> = Vec::with_capacity(n as usize);
        let seen = 0_u16;
        Self::dfs(n as u8, &mut k, &mut res, seen);

        String::from_utf8(res).unwrap()
    }
}
