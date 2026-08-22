use std::collections::{HashMap, HashSet};

impl Solution {
    fn dfs<'a>(
        curr: &'a str,
        curr_val: f64,
        target: &'a str,
        query_res: &mut Option<f64>,
        seen: &mut HashSet<&'a str>,
        graph: &HashMap<&'a str, HashMap<&'a str, f64>>
    ) {
        if query_res.is_some() {
            return;
        }

        if curr == target {
            *query_res = Some(curr_val);
            return;
        }

        if let Some(edges_curr) = graph.get(curr) {
            for (v, w) in edges_curr {
                if seen.insert(v) {
                    Self::dfs(v, curr_val * w, target, query_res, seen, graph);
                    seen.remove(v);
                }

                if query_res.is_some() {
                    return;
                }
            }
        }
    }
    pub fn calc_equation(equations: Vec<Vec<String>>, values: Vec<f64>, queries: Vec<Vec<String>>) -> Vec<f64> {
        assert!(equations.len() >= 1 && equations.len() <= 20 && equations.len() == values.len());

        let equations_len = equations.len();
        let mut graph: HashMap<&str, HashMap<&str, f64>> = HashMap::with_capacity(10 * equations_len);
        for i in 0..equations_len {
            let e = &equations[i];
            assert!(e.len() == 2);
            let (u, v): (&str, &str) = (&e[0], &e[1]);
            let w = values[i];
            assert!(w != 0.0_f64);
            graph.entry(u).or_insert(HashMap::new()).insert(v, w);
            graph.entry(v).or_insert(HashMap::new()).insert(u, 1.0_f64 / w);
        }

        let mut res = Vec::with_capacity(queries.len());
        let mut seen = HashSet::with_capacity(10 * equations_len);
        for q in &queries {
            let mut query_res: Option<f64> = None;
            let (u, v): (&str, &str) = (&q[0], &q[1]);

            if !graph.contains_key(&u) || !graph.contains_key(&v) {
                res.push(-1.0_f64);
            } else {
                Self::dfs(u, 1.0_f64, v, &mut query_res, &mut seen, &graph);
                seen.clear();

                match query_res {
                    None => res.push(-1.0_f64),
                    Some(v) => res.push(v),
                }
            }
        }

        res
    }
}
