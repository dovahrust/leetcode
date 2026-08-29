use std::cmp::Reverse;
use std::collections::BinaryHeap;

impl Solution {
    pub fn get_order(tasks: Vec<Vec<i32>>) -> Vec<i32> {
        let len = tasks.len();
        let mut tasks: Vec<(i32, i32, i32)> = tasks.into_iter().enumerate().map(|(i, t)| (t[0], t[1], i as i32)).collect();
        tasks.sort_unstable();
        let mut heap = BinaryHeap::with_capacity(len);
        let mut res: Vec<i32> = Vec::with_capacity(len);
        let mut idx = 0_usize;
        let mut curr_time = 0_i32;
        while idx < len {
            if heap.is_empty() { curr_time = curr_time.max(tasks[idx].0); }

            while idx < len && curr_time >= tasks[idx].0 {
                heap.push(Reverse((tasks[idx].1, tasks[idx].2)));
                idx += 1;
            }
            let Reverse((duration, task_id)) = heap.pop().unwrap();
            res.push(task_id);
            curr_time += duration;
        }

        while let Some(Reverse((_, task_id))) = heap.pop() {
            res.push(task_id);
        }

        res
    }
}
