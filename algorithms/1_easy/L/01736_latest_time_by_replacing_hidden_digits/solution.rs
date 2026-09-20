impl Solution {
    pub fn maximum_time(time: String) -> String {
        let mut t = time.into_bytes();
        if t[0] == b'?' {
            if t[1] == b'?' || (t[1] >= b'0' && t[1] <= b'3') {
                t[0] = b'2';
            } else {
                t[0] = b'1';
            }
        }

        if t[1] == b'?' {
            if t[0] == b'2' {
                t[1] = b'3';
            } else {
                t[1] = b'9';
            }
        }

        if t[3] == b'?' { t[3] = b'5'; }

        if t[4] == b'?' { t[4] = b'9'; }

        String::from_utf8(t).unwrap()
    }
}
