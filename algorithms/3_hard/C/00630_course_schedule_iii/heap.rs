use std::collections::BinaryHeap;

impl Solution {
    pub fn schedule_course(mut courses: Vec<Vec<i32>>) -> i32 {
        courses.sort_unstable_by(|a, b| a[1].cmp(&b[1]));
        let mut heap: BinaryHeap<i32> = BinaryHeap::with_capacity(courses.len());
        let mut sum = 0_i32;

        for c in courses {
            sum += c[0];
            let max_allowed = c[1];
            heap.push(c[0]);

            if sum > max_allowed {
                sum -= heap.pop().unwrap();
            }
        }

        heap.len().try_into().unwrap()
    }
}
