#[derive(Copy, Clone, Eq, PartialEq)]
enum State {
    NotFound,
    KeepSearch,
    Found(usize),
}

impl Solution {
    #[inline(always)]
    fn search(sb: &[u8], sb_idx: usize, pb: &[u8]) -> State {
        let sb_len = sb.len();
        let pb_len = pb.len();
        if sb_len - sb_idx < pb_len {
            return State::NotFound;
        }
        for i in 0..pb_len {
            if sb[sb_idx + i] != pb[i] && pb[i] != b'?' {
                return State::KeepSearch;
            }
        }
        State::Found(pb_len + sb_idx)
    }

    pub fn is_match(s: String, p: String) -> bool {
        if p.is_empty() { return s.is_empty(); }
        
        let end_with_star = *p.as_bytes().last().unwrap() == b'*';
        let parts = p.split('*').collect::<Vec<&str>>();
        let parts_len = parts.len();
        let sb = s.as_bytes();
        let sb_len = sb.len();
        let mut sb_idx: usize = 0;

        for (i, part) in parts.into_iter().enumerate() {
            let pb = part.as_bytes();
            let pb_len = pb.len();

            if pb_len == 0 { continue; }

            if i == 0 {
                if pb_len > sb_len || (0..pb_len).into_iter().any(|i| pb[i] != b'?' && pb[i] != sb[i]) {
                    return false;
                }
                sb_idx = pb_len;
            } else if i == parts_len - 1 {
                if pb_len > sb_len || sb_idx > sb_len - pb_len ||
                    (0..pb_len).into_iter().any(|i| pb[i] != b'?' && pb[i] != sb[sb_len - pb_len + i])  {
                    return false;
                }
                sb_idx = sb_len;
            } else {
                loop {
                    match Self::search(sb, sb_idx, pb) {
                        State::NotFound => return false,
                        State::KeepSearch => sb_idx += 1,
                        State::Found(end_idx) => {
                            sb_idx = end_idx;
                            break;
                        }
                    }
                }
            }
        }

        end_with_star || sb_idx == s.len()
    }
}
