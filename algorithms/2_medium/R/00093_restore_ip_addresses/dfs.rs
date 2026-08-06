impl Solution {
    fn dfs(bytes: &[u8], idx: usize, vals: &mut [u16; 4], vals_len: &mut usize, res: &mut Vec<String>) {
        if idx == bytes.len() {
            if *vals_len != 4 {
                return;
            }

            res.push(format!("{}.{}.{}.{}", vals[0], vals[1], vals[2], vals[3]));
            return;
        }

        let dig = (bytes[idx] - b'0') as u16;
        if *vals_len < 4 {
            vals[*vals_len] = dig;
            *vals_len += 1;
            Self::dfs(bytes, idx + 1, vals, vals_len, res);
            *vals_len -= 1;
        } 

        if *vals_len > 0 {
            let last = vals[*vals_len - 1];
            if last != 0 && (last * 10) + dig <= 255 {
                vals[*vals_len - 1] = (last * 10) + dig;
                Self::dfs(bytes, idx + 1, vals, vals_len, res);
                vals[*vals_len - 1] = last;
            }
        }
    }

    pub fn restore_ip_addresses(s: String) -> Vec<String> {
        let mut vals = [0_u16; 4];
        let mut vals_len = 0_usize;
        let mut res: Vec<String> = Vec::default();

        Self::dfs(s.as_bytes(), 0, &mut vals, &mut vals_len, &mut res);

        res
    }
}
