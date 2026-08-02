impl Solution {
    pub fn length_longest_path(input: String) -> i32 {
        let bytes = input.as_bytes();
        let bytes_len = bytes.len();
        let mut stack: Vec<usize> = Vec::new();
        let mut max_len = 0_usize;
        let mut last_len = 0_usize;
        let mut is_file = false;
        let mut stack_sum = 0_usize;
        let mut bytes_idx = 0_usize;

        while bytes_idx < bytes_len {
            match bytes[bytes_idx] {
                b'\n' => {
                    stack.push(last_len);
                    stack_sum += last_len;
                    last_len = 0;
                    let mut cnt_t = 0_usize;
                    while bytes_idx + 1 < bytes_len && bytes[bytes_idx + 1] == b'\t' {
                        cnt_t += 1;
                        bytes_idx += 1;
                    }
                    while cnt_t < stack.len() {
                        stack_sum -= stack.pop().unwrap();
                        is_file = false;
                    }
                },
                _ => {
                    last_len += 1;
                    if bytes[bytes_idx] == b'.' {
                        is_file = true;
                    }

                    if is_file {
                        max_len = max_len.max(last_len + stack_sum + stack.len());
                    }
                }
            }

            bytes_idx += 1;
        }

        max_len.try_into().unwrap()
    }
}
