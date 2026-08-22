impl Solution {
    pub fn find_smallest_set_of_vertices(n: i32, edges: Vec<Vec<i32>>) -> Vec<i32> {
        assert!(n >= 2 && n <= 100_000);
        let mut has_parent = vec![false; n as usize];

        for e in edges {
            let (u, v) = (e[0], e[1]);
            assert!(u >= 0 && u < n && v >= 0 && v < n);
            has_parent[v as usize] = true;
        }

        let mut res = Vec::<i32>::new();
        for i in 0..n {
            if !has_parent[i as usize] {
                res.push(i);
            }
        }

        res
    }
}
