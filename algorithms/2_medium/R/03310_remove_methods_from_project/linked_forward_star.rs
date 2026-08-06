struct Entity {
    v: i32,
    next: i32,
}

impl Solution {
    #[inline(always)]
    fn init_adj(edges: Vec<Vec<i32>>, n: i32) -> Vec<Entity> {
        let mut adj: Vec<Entity> = Vec::with_capacity(edges.len() + n as usize);
        for i in 0..n {
            adj.push(Entity { v: -1, next: -1 });
        }

        for e in edges {
            assert!(e.len() == 2);
            let (u, v) = (e[0], e[1]);
            assert!(u >= 0 && u < n && v >= 0 && v < n);
            let next = adj[u as usize].next;
            adj[u as usize].next = adj.len() as i32;
            adj.push(Entity { v: v, next: next });
        }

        adj
    }

    #[inline(always)]
    fn init_is_sus(n: i32, k: i32, adj: &[Entity]) -> Vec<bool> {
        let mut is_sus = vec![false; n as usize];
        let mut stack: Vec<i32> = Vec::with_capacity(n as usize);
        stack.push(k);
        is_sus[k as usize] = true;
        while let Some(u) = stack.pop() {
            let mut idx = adj[u as usize].next;
            while idx != -1 {
                let v = adj[idx as usize].v;
                if !is_sus[v as usize]  {
                    stack.push(v);
                    is_sus[v as usize] = true;
                }
                idx = adj[idx as usize].next;
            }
        }

        is_sus
    }

    pub fn remaining_methods(n: i32, k: i32, invocations: Vec<Vec<i32>>) -> Vec<i32> {
        assert!(n >= 1 && n <= 100_000 && k >= 0 && k < n && invocations.len() <= 200_000);
        let adj = Self::init_adj(invocations, n);
        let is_sus = Self::init_is_sus(n, k, &adj);

        for node in 0..n {
            if !is_sus[node as usize] {
                let mut idx = adj[node as usize].next;
                while idx != -1 {
                    let v = adj[idx as usize].v;
                    if is_sus[v as usize]  {
                        return (0..n).into_iter().collect::<Vec<i32>>();
                    }
                    idx = adj[idx as usize].next;
                }
            }
        }

        (0..n).into_iter().filter(|&node| !is_sus[node as usize]).collect::<Vec<i32>>()
    }
}
