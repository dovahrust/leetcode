use std::collections::BinaryHeap;

impl Solution {
    pub fn max_removal(mut nums: Vec<i32>, mut queries: Vec<Vec<i32>>) -> i32 {
        queries.sort_unstable_by(|a, b| {
            if a[0] == b[0] {
                b[1].cmp(&a[1])
            } else {
                a[0].cmp(&b[0])
            }
        });

        let len = nums.len();
        let queries_len = queries.len();
        let mut heap: BinaryHeap<i32> = BinaryHeap::with_capacity(queries_len);
        let mut pref = vec![0_i32; len + 1];
        let mut balance = 0_i32;
        let mut cnt = 0_i32;
        let mut queries_idx = 0_usize;

        for i in 0..len {
            balance += pref[i];
            let curr = nums[i];
            let pos = i as i32;

            while queries_idx < queries_len && queries[queries_idx][0] <= pos {
                if queries[queries_idx][1] < pos {
                    cnt += 1;
                } else {
                    heap.push(queries[queries_idx][1]);
                }

                queries_idx += 1;
            }

            while curr - balance > 0 {
                let Some(end) = heap.pop() else { return -1; };
                if end < i as i32 { return -1; }
                pref[(end + 1) as usize] -= 1;
                balance += 1;
            }
        }

        cnt + heap.len() as i32
    }
}
