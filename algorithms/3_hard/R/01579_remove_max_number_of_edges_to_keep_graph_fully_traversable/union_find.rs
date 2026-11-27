impl Solution {
    fn find_parent(parents: &mut [usize], mut u: usize) -> usize {
        while let p = parents[u] && p != u {
            parents[u] = parents[p];
            u = parents[u];
        }
        u
    }

    pub fn helper(edges: &[Vec<i32>], parents: &mut [usize], target: i32) -> usize {
        let mut cnt: usize = 0;

        for e in edges {
            let (t, u, v) = (e[0], e[1] as usize, e[2] as usize);

            if t != target { continue; }

            let pu = Self::find_parent(parents, u);
            let pv = Self::find_parent(parents, v);

            if pv == pu { continue; }

            parents[pv] = pu;
            cnt += 1;
        }

        cnt
    }

    pub fn max_num_edges_to_remove(n: i32, edges: Vec<Vec<i32>>) -> i32 {
        let n = n as usize;
        let mut parents: Vec<usize> = (0..(n + 1)).collect();

        let base_cnt = Self::helper(&edges, &mut parents, 3);

        let mut alice = parents.clone();
        let mut bob = parents;

        let alice_cnt = Self::helper(&edges, &mut alice, 1);
        let root = Self::find_parent(&mut alice, 1);
        if !(1..=n).all(|u| Self::find_parent(&mut alice, u) == root) { return -1; }

        let bob_cnt = Self::helper(&edges, &mut bob, 2);
        let root = Self::find_parent(&mut bob, 1);
        if !(1..=n).all(|u| Self::find_parent(&mut bob, u) == root) { return -1; }

        (edges.len() - (base_cnt + alice_cnt + bob_cnt)).try_into().unwrap()
    }
}
