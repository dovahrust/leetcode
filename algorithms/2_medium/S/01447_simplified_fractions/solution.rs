impl Solution {
    #[inline(always)]
    fn gcd(mut a: i32, mut b: i32) -> i32 {
        while b != 0 {
            let t = b;
            b = a % b;
            a = t;
        }
        a
    }

    pub fn simplified_fractions(n: i32) -> Vec<String> {
        let mut res: Vec<String> = Vec::new();
        for i in 1..n {
            for j in (i + 1)..=n {
                if Self::gcd(i, j) == 1 {
                    res.push(format!("{i}/{j}"));
                }
            }
        }
        res
    }
}
