impl Solution {
    pub fn merge_characters(s: String, k: i32) -> String {
        let mut bytes = s.into_bytes();
        let len = bytes.len();
        assert!(len <= 100);
        let k = k as i8;
        let mut prev_idx = [-1_i8; 26];
        let mut stack_len = 0_i8;

        for i in 0..len {
            let b = bytes[i];
            assert!(b >= b'a' && b <= b'z');
            if prev_idx[(b - b'a') as usize] == -1 || stack_len - prev_idx[(b - b'a') as usize] > k {
                prev_idx[(b - b'a') as usize] = stack_len;
                bytes[stack_len as usize] = b;
                stack_len += 1;
            }
        }

        bytes.truncate(stack_len as usize);

        String::from_utf8(bytes).unwrap()
    }
}
