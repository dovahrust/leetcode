impl Solution {
    pub fn remove_outer_parentheses(s: String) -> String {
        let mut bytes: Vec<u8> = s.into_bytes();
        let len = bytes.len();
        let mut balance: isize = 0;
        let mut write_idx: usize = 0;

        for read_idx in 0..len {
            let byte = bytes[read_idx];

            if byte == b'(' {
                balance += 1;
            } else {
                balance -= 1;
            }

            if (balance == 1 && byte == b'(') || balance == 0 {
               continue;
            }

            bytes[write_idx] = byte;
            write_idx += 1;
        }

        unsafe { bytes.set_len(write_idx) };

        String::from_utf8(bytes).unwrap()
    }
}
