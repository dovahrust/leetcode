impl Solution {
    pub fn min_operations(s: String) -> i32 {
        let (mut zero_first, mut one_first) = (0_usize, 0_usize);

        for (i, &byte) in s.as_bytes().into_iter().enumerate() {
            if (i & 1) == 0 {
                match byte {
                    b'0' => one_first += 1,
                    b'1' => zero_first += 1,
                    _ => unreachable!(),
                }
            } else {
                match byte {
                    b'0' => zero_first += 1,
                    b'1' => one_first += 1,
                    _ => unreachable!(),
                }
            }
        }

        zero_first.min(one_first).try_into().unwrap()
    }
}
