use std::collections::BinaryHeap;
use std::cmp::Reverse;

impl Solution {
    pub fn minimum_time(n: i32, relations: Vec<Vec<i32>>, time: Vec<i32>) -> i32 {
        let mut adj: Vec<Vec<i32>> = vec![Vec::new(); n as usize];
        let mut deg: Vec<u32> = vec![0_u32; n as usize];
        for r in relations {
            let (u, v) = (r[0] - 1, r[1] - 1);
            deg[v as usize] += 1;
            adj[u as usize].push(v);
        }

        let mut heap: BinaryHeap<Reverse<(i32, i32)>> = BinaryHeap::with_capacity(n as usize);

        for (u, &d) in deg.iter().enumerate() {
            if d == 0 {
                heap.push(Reverse((time[u], u as i32)));
            }
        }

        let mut res: i32 = 0;
        while let Some(Reverse((prev_end, u))) = heap.pop() {
            res = prev_end;

            for &v in &adj[u as usize] {
                deg[v as usize] -= 1;
                if deg[v as usize] == 0 {
                    heap.push(Reverse((prev_end + time[v as usize], v)));
                }
            }
        }

        res
    }
}
