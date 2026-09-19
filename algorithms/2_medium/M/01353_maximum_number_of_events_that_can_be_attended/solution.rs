use std::collections::BinaryHeap;
use std::cmp::Reverse;

impl Solution {
    pub fn max_events(events: Vec<Vec<i32>>) -> i32 {
        let mut events: Vec<(i32, i32)> = events.into_iter().map(|x| (x[0], x[1])).collect();
        events.sort_unstable_by_key(|x| x.0);
        let len = events.len();
        let mut curr = i32::MIN;
        let mut cnt: usize = 0;
        let mut heap = BinaryHeap::with_capacity(len);
        let mut idx: usize = 0;

        while idx < len || !heap.is_empty() {
            if heap.is_empty() && idx < len {
                curr = curr.max(events[idx].0);
            }

            while idx < len && events[idx].0 == curr {
                heap.push(Reverse(events[idx].1));
                idx += 1;
            }

            if heap.pop().is_some() {
                cnt += 1;
            }

            curr += 1;

            while let Some(Reverse(top)) = heap.peek() && *top < curr {
                heap.pop();
            }
        }

        cnt.try_into().unwrap()
    }
}
