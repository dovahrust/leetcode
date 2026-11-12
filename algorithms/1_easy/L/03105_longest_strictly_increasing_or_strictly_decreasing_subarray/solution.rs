#[derive(Eq, PartialEq)]
enum States {
    Dec,
    Neu,
    Inc,
}

impl Solution {
    pub fn longest_monotonic_subarray(nums: Vec<i32>) -> i32 {
        if nums.is_empty() { return -1; }

        let mut longest: usize = 1;
        let mut curr: usize = 0;
        let len = nums.len();
        let mut state = States::Neu;

        for w in nums.windows(2) {
            if w[1] > w[0] {
                if state != States::Inc {
                    curr = 2;
                    state = States::Inc;
                } else {
                    curr += 1;
                }
            } else if w[1] < w[0] {
                if state != States::Dec {
                    curr = 2;
                    state = States::Dec;
                } else {
                    curr += 1;
                }
            } else {
                state = States::Neu;
                curr = 1;
            }

            longest = longest.max(curr);
        }

        longest.try_into().unwrap()
    }
}
