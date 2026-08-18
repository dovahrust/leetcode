use std::collections::BinaryHeap;
use std::cmp::Reverse;

impl Solution {
    const MOD: i64 = 1_000_000_007;

    pub fn count_paths(n: i32, roads: Vec<Vec<i32>>) -> i32 {
        assert!(n > 0 && n <= 200);
        let mut adj: Vec<Vec<(i32, i32)>> = vec![Vec::default(); n as usize];
        for r in roads {
            assert!(r.len() == 3);
            let (u, v, w) = (r[0], r[1], r[2]);
            assert!(u >= 0 && u < n && v >= 0 && v < n && w >= 1);
            adj[u as usize].push((v, w));
            adj[v as usize].push((u, w));
        }

        let mut heap: BinaryHeap<Reverse<(i64, i32)>> = BinaryHeap::with_capacity(2 * n as usize);
        let mut costs = vec![(i64::MAX, 0_i64); n as usize];
        heap.push(Reverse((0, 0)));
        costs[0] = (0, 1);

        while let Some(Reverse((cost, u))) = heap.pop() {
            if cost > costs[u as usize].0 { continue; }

            let ways = costs[u as usize].1;

            for &(v, w) in &adj[u as usize] {
                let new_cost = cost + w as i64;
                if new_cost < costs[v as usize].0 {
                    costs[v as usize].0 = new_cost;
                    costs[v as usize].1 = ways;
                    heap.push(Reverse((new_cost, v)));
                } else if new_cost == costs[v as usize].0 {
                    costs[v as usize].1 = (costs[v as usize].1 + ways) % Self::MOD;
                }
            }
        }

        costs[(n - 1) as usize].1 as i32
    }
}
