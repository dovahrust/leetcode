impl Solution {
    pub fn minimum_pushes(word: String) -> i32 {
        assert!(word.len() <= 26);
        let n = word.len() as i32;

        n + (n - n.min(8)) + (n - n.min(16)) +  (n - n.min(24))
    }
}
