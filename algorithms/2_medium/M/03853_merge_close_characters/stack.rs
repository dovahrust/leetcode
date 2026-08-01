impl Solution {
    pub fn merge_characters(s: String, k: i32) -> String {
        let k = k as isize;
        let mut prev_idx = [-1_isize; 256];
        let mut stack: Vec<u8> = Vec::with_capacity(s.len());

        for &b in s.as_bytes() {
            if prev_idx[b as usize] == -1 || (stack.len() as isize) - prev_idx[b as usize] > k {
                prev_idx[b as usize] = stack.len() as isize;
                stack.push(b);
            }
        }

        String::from_utf8(stack).unwrap()
    }
}
