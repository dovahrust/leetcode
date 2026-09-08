#[derive(Clone, Copy, Eq, PartialEq)]
enum State {
    None,
    InProgress,
    Seen,
}

impl Solution {
    fn dfs(adj: &[Vec<i32>], curr: i32, states: &mut[State]) -> bool {
        if states[curr as usize] == State::InProgress { return false; }

        if states[curr as usize] == State::Seen { return true; } 

        states[curr as usize] = State::InProgress;
        for &v in &adj[curr as usize] {
            if !Self::dfs(adj, v, states) {
                return false;
            }
        }
        states[curr as usize] = State::Seen;

        true
    }

    fn init_adj(num_courses: i32, prerequisites: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut adj: Vec<Vec<i32>> = vec![Vec::default(); num_courses as usize];
        for p in prerequisites {
            assert!(p.len() == 2);
            let (u, v) = (p[0], p[1]);
            assert!(u >= 0 && v >= 0 && u < num_courses && v < num_courses);
            adj[u as usize].push(v);
        }
        adj
    }

    pub fn can_finish(num_courses: i32, prerequisites: Vec<Vec<i32>>) -> bool {
        assert!(num_courses >= 1 && num_courses <= 2000);
        let mut states = vec![State::None; num_courses as usize];
        let mut adj = Self::init_adj(num_courses, prerequisites);
        
        for i in 0..num_courses {
            if !Self::dfs(&adj, i, &mut states) {
                return false;
            }
        }

        true
    }
}
