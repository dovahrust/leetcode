impl Solution {
    const HAMSTER: u8 = b'H';
    const EMPTY: u8 = b'.';

    pub fn minimum_buckets(hamsters: String) -> i32 {
        let bytes = hamsters.as_bytes();
        let len = bytes.len();
        let mut i: usize = 0;
        let mut cnt: usize = 0;

        while i < len {
            if bytes[i] == Self::HAMSTER {
                if i + 1 < len && bytes[i + 1] == Self::EMPTY {
                    i += 3;
                    cnt += 1;
                } else if i > 0 && bytes[i - 1] == Self::EMPTY {
                    cnt += 1;
                    i += 1;
                } else {
                    return -1;
                }
            } else {
                i += 1;
            }
        }

        cnt.try_into().unwrap()
    }
}
