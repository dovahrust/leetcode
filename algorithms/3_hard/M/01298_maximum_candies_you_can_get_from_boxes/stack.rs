#[derive(Clone, Copy, Eq, PartialEq)]
enum State {
    None,
    HasKey,
    HasBox,
    Visited,
}

impl Solution {
    pub fn max_candies(
        status: Vec<i32>, 
        candies: Vec<i32>,
        keys: Vec<Vec<i32>>,
        contained_boxes: Vec<Vec<i32>>,
        initial_boxes: Vec<i32>,
    ) -> i32 {
        let n = status.len();
        assert!(n <= 1000 && n >= 1);
        let mut states = vec![State::None; n];
        let mut stack: Vec<usize> = Vec::with_capacity(n);
        let mut cnt = 0_i32;

        for (i, &is_open) in status.iter().enumerate() {
            if is_open == 1 {
                states[i] = State::HasKey;
            }
        }

        for i in initial_boxes {
            let i = i as usize;
            if states[i] == State::HasKey {
                states[i] = State::Visited;
                stack.push(i);
            } else {
                states[i] = State::HasBox;
            }
        }

        while let Some(i) = stack.pop() {
            cnt += candies[i];

            for &key in &keys[i] {
                states[key as usize] = match states[key as usize] {
                    State::Visited => State::Visited,
                    State::None | State::HasKey => State::HasKey,
                    State::HasBox => {
                        stack.push(key as usize);
                        State::Visited
                    },
                }
            }

            for &box_idx in &contained_boxes[i] {
                states[box_idx as usize] = match states[box_idx as usize] {
                    State::Visited => State::Visited,
                    State::None | State::HasBox => State::HasBox,
                    State::HasKey => {
                        stack.push(box_idx as usize);
                        State::Visited
                    },
                }
            }
        }

        cnt
    }
}
