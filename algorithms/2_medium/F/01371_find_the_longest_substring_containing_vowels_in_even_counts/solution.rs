impl Solution {
    #[inline(always)]
    fn get_mask_byte(b: u8) -> usize {
        match b {
            b'a' => 1,
            b'e' => (1 << 1),
            b'i' => (1 << 2),
            b'o' => (1 << 3),
            b'u' => (1 << 4),
            _ => 0,
        }
    }

    pub fn find_the_longest_substring(s: String) -> i32 {
        let mut first_seen: [Option<isize>; 32] = [None; 32];
        first_seen[0] = Some(-1);
        let mut curr_state = 0_usize;
        let mut longest = 0_isize;

        for (i, &b) in s.as_bytes().iter().enumerate() {
            let mask = Self::get_mask_byte(b);
            curr_state ^= mask;
            if let Some(state) = first_seen[curr_state] {
                longest = longest.max((i as isize) - state);
            } else {
                first_seen[curr_state] = Some(i as isize);
            }
        }

        longest.try_into().unwrap()
    }
}
