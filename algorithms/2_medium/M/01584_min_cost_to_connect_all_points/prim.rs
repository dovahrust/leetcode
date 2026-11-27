impl Solution {
    pub fn min_cost_connect_points(points: Vec<Vec<i32>>) -> i32 {
        let n = points.len();
        let mut in_tree = vec![false; n];
        let mut min_dist = vec![i32::MAX; n];
        min_dist[0] = 0;
        let mut cost: i32 = 0;

        for _ in 0..n {
            let mut u = usize::MAX;
            let mut best = i32::MAX;

            for v in 0..n {
                if !in_tree[v] && min_dist[v] < best {
                    u = v;
                    best = min_dist[v];
                }
            }

            cost += best;
            in_tree[u] = true;
            let (ux, uy) = (points[u][0], points[u][1]);

            for v in 0..n {
                if !in_tree[v] {
                    let d = (ux - points[v][0]).abs() + (uy - points[v][1]).abs();
                    
                    min_dist[v] = min_dist[v].min(d);
                }
            }
        }

        cost
    }
}
