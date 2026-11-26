use std::collections::BinaryHeap;
use std::cmp::Reverse;

impl Solution {
    pub fn min_time(n: i32, edges: Vec<Vec<i32>>) -> i32 {
        if n == 1 { return 0; }

        let n = n as usize;
        let mut adj = vec![Vec::new(); n];
        for e in edges {
            let (u, v, start, end) = (e[0], e[1], e[2], e[3]);
            adj[u as usize].push((v as usize, start, end));
        }
        let mut costs = vec![i32::MAX; n];
        let mut heap: BinaryHeap<Reverse<(i32, usize)>> = BinaryHeap::with_capacity(2 * n);
        heap.push(Reverse((0, 0)));
        costs[0] = 0;

        while let Some(Reverse((t, u))) = heap.pop() {
            if t > costs[u] { continue; }

            if u == n - 1 { return t; }

            for &(v, st, en) in &adj[u] {
                if t <= en {
                    let cost = t.max(st) + 1;
                    if cost < costs[v] {
                        costs[v] = cost;
                        heap.push(Reverse((cost, v)));
                    }
                }
            }
        }

        -1
    }
}
