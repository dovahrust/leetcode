impl Solution {
    pub fn min_changes(s: String) -> i32 {
        s.as_bytes().chunks(2).filter(|w| w[0] != w[1]).count() as i32
    }
}
