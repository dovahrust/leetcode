impl Solution {
    pub fn can_reach(s: String, min_jump: i32, max_jump: i32) -> bool {
        assert!(min_jump >= 1 && min_jump <= max_jump);
        let (min_jump, max_jump) = (min_jump as usize, max_jump as usize);
        let bytes = s.as_bytes();
        let len = bytes.len();
        assert!(len >= 2 && len <= 100_000);
        if bytes[len - 1] != b'0' || bytes[0] != b'0' { return false; }
        let mut diff = vec![0; len + 1];
        diff[0] = 1;
        diff[1] = -1;

        let mut balance = 0_i32;
        for (i, &b) in bytes.into_iter().enumerate() {
            balance += diff[i];
            if balance > 0 {
                if i == len - 1 {
                    return true;
                }

                if b != b'0' {
                    continue;
                }

                let begin = (i + min_jump).min(len);
                let end = (i + max_jump + 1).min(len);

                diff[begin] += 1;
                diff[end] -= 1;
            }
        }

        false
    }
}
