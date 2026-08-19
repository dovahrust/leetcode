impl Solution {
    const CHANGE_LEN: usize = 10;

    pub fn maximum_number(num: String, change_vec: Vec<i32>) -> String {
        assert!(change_vec.len() == Self::CHANGE_LEN);

        if (0..Self::CHANGE_LEN).into_iter().all(|x| (x as i32) >= change_vec[x]) {
            return num;
        }

        let mut change = [0_u8; Self::CHANGE_LEN];
        for i in 0..Self::CHANGE_LEN {
            let x = change_vec[i];
            assert!(x >= 0 && x <= 9);
            change[i] = b'0' + change_vec[i] as u8;
        }

        let mut bytes = num.into_bytes();
        let mut has_changed = false;
        for b in bytes.iter_mut() {
            assert!(*b >= b'0' && *b <= b'9');
            let idx = ((*b) - b'0') as usize;
            if *b < change[idx] {
                *b = change[idx];
                has_changed = true;
            } else if has_changed && *b != change[idx] {
                break;
            }
        }

        String::from_utf8(bytes).unwrap()
    }
}
