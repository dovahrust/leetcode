impl Solution {
    pub fn reverse_prefix(s: String, k: i32) -> String {
        let mut bytes = s.into_bytes();
        bytes[0..(k as usize)].reverse();
        String::from_utf8(bytes).unwrap()
    }
}
