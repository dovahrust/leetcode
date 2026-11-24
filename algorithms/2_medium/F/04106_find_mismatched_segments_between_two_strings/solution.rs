impl Solution {
    pub fn find_mismatched_segments(s1: String, s2: String) -> Vec<Vec<String>> {
        assert!(s1.len() == s2.len());
        let len = s1.len();
        let (b1, b2) = (s1.as_bytes(), s2.as_bytes());
        let mut res: Vec<Vec<String>> = Vec::new();
        let mut i: usize = 0;
        while i < len {
            let mut j = i;
            while j < len && b1[j] != b2[j] { j += 1; }

            if j > i {
                res.push(vec![
                    String::from_utf8_lossy(&b1[i..j]).into_owned(),
                    String::from_utf8_lossy(&b2[i..j]).into_owned(),
                ]);
            }

            i = j + 1;
        }

        res
    }
}
