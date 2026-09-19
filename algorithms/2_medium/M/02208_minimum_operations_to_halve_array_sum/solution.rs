use std::collections::BinaryHeap;
use std::cmp::Ordering;

#[derive(Debug, Clone, Copy, PartialEq)]
struct OrdF64(f64);

impl Eq for OrdF64 {}

impl PartialOrd for OrdF64 {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

impl Ord for OrdF64 {
    fn cmp(&self, other: &Self) -> Ordering {
        self.0.partial_cmp(&other.0).unwrap()
    }
}

impl Solution {
    pub fn halve_array(nums: Vec<i32>) -> i32 {
        let sum: f64 = nums.iter().map(|&x| x as f64).sum();
        let target = sum / 2.0_f64;
        let mut heap: BinaryHeap<OrdF64> = nums.into_iter().map(|x| OrdF64(x as f64)).collect();
        let mut curr: f64 = 0.0;
        let mut cnt: i32 = 0;

        while curr < target {
            let OrdF64(top) = heap.pop().unwrap();
            let half = top / 2.0_f64;
            curr += half;
            heap.push(OrdF64(half));
            cnt += 1;
        }

        cnt
    }
}
