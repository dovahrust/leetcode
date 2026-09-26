use std::collections::HashMap;

impl Solution {
    pub fn evaluate(s: String, knowledge: Vec<Vec<String>>) -> String {
        let mut hashmap: HashMap<&[u8], &[u8]> = HashMap::with_capacity(2 * knowledge.len());
        for k in knowledge.iter() {
            hashmap.insert(k[0].as_bytes(), k[1].as_bytes());
        }

        let mut res: Vec<u8> = Vec::new();
        let mut i = 0_usize;
        let bytes = s.as_bytes();
        let len = bytes.len();

        while i < len {
            if bytes[i] == b'(' {
                i += 1;

                let begin = i;
                while i < len && bytes[i] != b')' {
                    i += 1;
                }
                let end = i;

                if let Some(val) = hashmap.get(&bytes[begin..end]) {
                    res.extend_from_slice(val);
                } else {
                    res.push(b'?');
                }
            } else {
                res.push(bytes[i]);
            }

            i += 1;
        }

        String::from_utf8(res).unwrap()
    }
}
