impl Solution {
    pub fn get_smallest_string(n: i32, mut k: i32) -> String {
        let mut res = vec![b'a'; n as usize];
        k -= n;
        for b in res.iter_mut().rev() {
            if k <= 25 {
                *b += (k as u8);
                break;
            } else {
                *b += 25;
                k -= 25;
            }
        }

        String::from_utf8(res).unwrap()
    }
}
