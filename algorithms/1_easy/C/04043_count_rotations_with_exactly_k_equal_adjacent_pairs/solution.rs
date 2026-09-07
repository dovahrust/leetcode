impl Solution {
    pub fn count_rotations(s: String, k: i32) -> i32 {
        assert!(s.len() >= 2 && s.len() <= 100);
        let bytes = s.as_bytes();
        let len = bytes.len();
        let (mut eq, mut ne) = (0_i32, 0_i32);
        for i in 1..len {
            if bytes[i] == bytes[i - 1] {
                eq += 1;
            } else {
                ne += 1;
            }
        }
        if bytes[len - 1] == bytes[0] {
            eq += 1;
        } else {
            ne += 1;
        }

        if k == eq - 1 {
            return eq;
        }

        if k == eq {
            return ne;
        }

        0
    }
}
