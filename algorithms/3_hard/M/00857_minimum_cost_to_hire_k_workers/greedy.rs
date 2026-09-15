use std::collections::BinaryHeap;

impl Solution {
    pub fn mincost_to_hire_workers(quality: Vec<i32>, wage: Vec<i32>, k: i32) -> f64 {
        let n = quality.len();
        let k = k as usize;
        let mut data: Vec<(f64, i32)> = Vec::with_capacity(n);
        let mut heap: BinaryHeap<i32> = BinaryHeap::with_capacity(k);

        for i in 0..n {
            let r = (wage[i] as f64) / (quality[i] as f64);
            data.push((r, quality[i]));
        }

        data.sort_unstable_by(|a, b| a.0.partial_cmp(&b.0).unwrap());

        let mut sum: i32 = 0;
        let mut res: f64 = f64::MAX;

        for (r, q) in data {
            sum += q;
            heap.push(q);

            if heap.len() == k {
                res = res.min((sum as f64) * r);
                sum -= heap.pop().unwrap();
            }
        }

        res
    }
}
