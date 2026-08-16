impl Solution {
    const MAX_ALLOWED: usize = 100;

    pub fn find_champion(n: i32, edges: Vec<Vec<i32>>) -> i32 {
        assert!(n >= 1 && (n as usize) <= Self::MAX_ALLOWED);
        let mut parent = [-1_i8; Self::MAX_ALLOWED];

        for e in edges {
            assert!(e.len() == 2);
            let (u, v) = (e[0], e[1]);
            assert!(u >= 0 && v >= 0 && u < n && v < n);

            parent[v as usize] = u as i8;
        }

        let mut res = -1_i32;
        for i in 0..n {
            if parent[i as usize] == -1 {
                if res == -1 {
                    res = i as i32;
                } else {
                    return -1;
                }
            }
        }

        res
    }
}
