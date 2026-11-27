impl Solution {
    fn find_parent(parents: &mut [usize], mut u: usize) -> usize {
        while let p = parents[u] && p != u {
            parents[u] = parents[p];
            u = parents[u];
        }
        u
    }

    pub fn validate_binary_tree_nodes(n: i32, left_child: Vec<i32>, right_child: Vec<i32>) -> bool {
        let n = n as usize;
        let mut parents: Vec<usize> = (0..n).collect();

        for u in 0..n {
            for v in [left_child[u], right_child[u]] {
                if v == - 1 { continue; }

                let v = v as usize;

                if u == v { return false; }

                let pu = Self::find_parent(&mut parents, u);
                let pv = Self::find_parent(&mut parents, v);

                if pv != v { return false; }

                if pv == pu { return false; }

                parents[v] = pu;
            }
        }

        let root = Self::find_parent(&mut parents, 0);

        (0..n).all(|u| Self::find_parent(&mut parents, u) == root)
    }
}
