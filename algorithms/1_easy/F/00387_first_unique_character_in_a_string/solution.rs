#[derive(Clone, Copy, Eq, PartialEq)]
enum State {
    NotSeen,
    OnceSeen(usize),
    MultiSeen,
}

impl Solution {
    pub fn first_uniq_char(s: String) -> i32 {
        let mut states = [State::NotSeen; 256];

        for (i, &byte) in s.as_bytes().into_iter().enumerate() {
            if states[byte as usize] == State::NotSeen {
                states[byte as usize] = State::OnceSeen(i);
            } else {
                states[byte as usize] = State::MultiSeen;
            }
        }

        let mut res: Option<usize> = None;

        for state in states {
            if let State::OnceSeen(idx) = state {
                res = Some(res.map_or(idx, |other_idx| other_idx.min(idx)));
            }
        }

        match res {
            None => -1,
            Some(idx) => idx.try_into().unwrap(),
        }
    }
}
