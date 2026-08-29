impl Solution {
    pub fn count_vowel_strings(n: i32) -> i32 {
        assert!(n >= 1 && n <= 50);
        let mut prev = [1_i32; 5];
        let mut curr = [0_i32; 5];

        for _ in 1..n {
            curr.iter_mut().for_each(|x| *x = 0);
            for i in 0..5 {
                for j in 0..=i {
                    curr[j] += prev[i];
                }
            }
            (curr, prev) = (prev, curr);
        }

        prev.into_iter().sum()
    }
}
