impl Solution {
    pub fn min_queen_moves(source: Vec<i32>, target: Vec<i32>) -> i32 {
        let (si, sj) = (source[0], source[1]);
        let (ti, tj) = (target[0], target[1]);

        if si == ti && sj == tj { return 0; }

        if si == ti || sj == tj { return 1; }

        if (si - ti).abs() == (sj - tj).abs() { return 1; }

        2
    }
}
