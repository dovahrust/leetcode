impl Solution {
    pub fn slowest_key(release_times: Vec<i32>, keys_pressed: String) -> char {
        let mut prev: i32 = 0;
        let mut duration = [0_i32; 256];
        for (i, &b) in keys_pressed.as_bytes().into_iter().enumerate() {
            duration[b as usize] =  duration[b as usize].max(release_times[i] - prev);
            prev = release_times[i];
        }

        let mut longest: i32 = 0;
        let mut longest_byte: u8 = 0;
        for b in 0..255 {
            if duration[b] >= longest {
                longest = duration[b];
                longest_byte = b as u8;
            }
        }

        longest_byte as char
    }
}
