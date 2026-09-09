impl Solution {
    #[inline(always)]
    fn is_valid(bytes: &[u8]) -> bool {
        let len = bytes.len();

        match len {
            0 => false,
            1 => true,
            _ => !(bytes[0] == b'0' && bytes[len - 1] == b'0'),
        }
    }

    fn dfs(s: &[u8], idx: usize, can_push_dot: bool, tmp: &mut Vec<u8>, nums: &mut Vec<Vec<u8>>) {
        if idx == s.len() {
            nums.push(tmp.clone());
            return;
        }

        match idx {
            0 => {
                tmp.push(s[idx]);
                Self::dfs(s, idx + 1, can_push_dot, tmp, nums);
                tmp.pop();
            },
            1 => {
                if can_push_dot { 
                    tmp.push(b'.');
                    tmp.push(s[idx]);
                    Self::dfs(s, idx + 1, false, tmp, nums);
                    tmp.pop();
                    tmp.pop();
                }

                if s[0] != b'0' {
                    tmp.push(s[idx]);
                    Self::dfs(s, idx + 1, can_push_dot, tmp, nums);
                    tmp.pop();
                }
            },
            _ => {
                tmp.push(s[idx]);
                Self::dfs(s, idx + 1, can_push_dot, tmp, nums);
                tmp.pop();

                if can_push_dot {
                    tmp.push(b'.');
                    tmp.push(s[idx]);
                    Self::dfs(s, idx + 1, false, tmp, nums);
                    tmp.pop();
                    tmp.pop();
                }
            }
        }
    }

    pub fn ambiguous_coordinates(s: String) -> Vec<String> {
        let bytes = s.as_bytes();
        let len = bytes.len();
        assert!(
            len >= 4 &&
            bytes[0] == b'(' && bytes[len - 1] == b')' &&
            (1..=(len - 2)).into_iter().all(|x| bytes[x] >= b'0' && bytes[x] <= b'9')
        );

        let mut res: Vec<String> = Vec::new();
        let mut nums1: Vec<Vec<u8>> = Vec::new();
        let mut nums2: Vec<Vec<u8>> = Vec::new();
        let mut tmp: Vec<u8> = Vec::new();

        let (lo, hi) = (1, len - 2);
        for i in lo..hi {
            if Self::is_valid(&bytes[lo..=i]) && Self::is_valid(&bytes[(i + 1)..=hi]) {
                nums1.clear();
                nums2.clear();
                Self::dfs(&bytes[lo..=i], 0, bytes[i] != b'0', &mut tmp, &mut nums1);
                Self::dfs(&bytes[(i + 1)..=hi], 0,  bytes[hi] != b'0', &mut tmp, &mut nums2);
                
                for n1 in &nums1 {
                    for n2 in &nums2 {
                        let mut val: Vec<u8> = Vec::with_capacity(n1.len() + n2.len() + 4);
                        val.push(b'(');
                        val.extend_from_slice(n1);
                        val.push(b',');
                        val.push(b' ');
                        val.extend_from_slice(n2);
                        val.push(b')');

                        res.push(String::from_utf8(val).unwrap());
                    }
                }
            }
        }

        res
    }
}
