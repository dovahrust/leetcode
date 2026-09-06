impl Solution {
    pub fn does_alice_win(s: String) -> bool {
        s.as_bytes().iter().any(|&b| matches!(b, b'a' | b'e' | b'i' | b'o' | b'u'))
    }
}
