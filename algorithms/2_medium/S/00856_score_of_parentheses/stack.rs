impl Solution {
    pub fn score_of_parentheses(s: String) -> i32 {
        let mut stack: Vec<i32> = Vec::new();
        let mut score = 0_i32;

        for &byte in s.as_bytes() {
            match byte {
                b'(' => stack.push(0),
                b')' => {
                    let curr = 1_i32.max(stack.pop().expect("invalid input"));
                    if let Some(val) = stack.last_mut() {
                        *val += 2 * curr;
                    } else {
                        score += curr;
                    }
                }
                _ => unreachable!("invalid input"),
            }
        }

        score
    }
}
