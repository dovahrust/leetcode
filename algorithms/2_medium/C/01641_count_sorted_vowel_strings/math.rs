impl Solution {
    pub fn count_vowel_strings(n: i32) -> i32 {
        assert!(n >= 1 && n <= 50);
        (n + 1) * (n + 2) * (n + 3) * (n + 4) / 24
    }
}
