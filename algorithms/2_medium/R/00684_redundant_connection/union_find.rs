impl Solution {
    fn find_parent(parents: &mut [Option<usize>], mut u: usize) -> Option<usize> {
        loop {
            let p = parents[u]?;
            if p == u { return Some(u); }

            parents[u] = parents[p];
            u = p;
        }
    }

    pub fn find_redundant_connection(edges: Vec<Vec<i32>>) -> Vec<i32> {
        let n = edges.len();
        let mut parents: Vec<Option<usize>> = vec![None; n + 1];
        let mut size: Vec<usize> = vec![0; n + 1];

        for e in edges {
            let (u, v) = (e[0] as usize, e[1] as usize);

            match (Self::find_parent(&mut parents, u), Self::find_parent(&mut parents, v)) {
                (None, None) => {
                    parents[u] = Some(u);
                    parents[v] = Some(u);
                    size[u] += 2;
                },
                (Some(x), None) => {
                    parents[v] = Some(x);
                    size[x] += 1;
                },
                (None, Some(x)) => {
                    parents[u] = Some(x);
                    size[x] += 1;
                },
                (Some(x), Some(y)) => {
                    if x == y { return e; }

                    if size[x] > size[y] {
                        size[x] += size[y];
                        parents[y] = Some(x);
                    } else {
                        size[y] += size[x];
                        parents[x] = Some(y);
                    }

                }
            }
        }

        unreachable!("invalid input")
    }
}
