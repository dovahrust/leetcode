impl Solution {
    pub fn divide_string(s: String, k: i32, fill: char) -> Vec<String> {
        let k = k as usize;
        let bytes = s.as_bytes();
        let b_len = bytes.len();
        let fill = fill as u8;
        let res_len = (b_len + k - 1) / k;
        let mut res = vec![String::new(); res_len];

        for i in 0..res_len {
            let mut v: Vec<u8> = Vec::with_capacity(k);
            for j in (i * k)..(i * k + k) {
                v.push(*bytes.get(j).unwrap_or(&fill));
            }
            res[i] = String::from_utf8(v).unwrap();
        }

        res
    }
}
