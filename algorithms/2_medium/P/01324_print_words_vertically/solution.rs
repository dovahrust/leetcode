impl Solution {
    pub fn print_vertically(s: String) -> Vec<String> {
        let mut res: Vec<String> = Vec::default();

        for (cnt, word) in s.split_whitespace().into_iter().enumerate() {
            while word.len() > res.len() {
                res.push(String::from_utf8(vec![b' '; cnt]).unwrap());
            }

            for (idx, &byte) in word.as_bytes().iter().enumerate() {
                let steps = cnt - res[idx].len();
                res[idx].extend(std::iter::repeat_n(' ', steps));
                res[idx].push(byte as char);
            }
        }

        res
    }
}
