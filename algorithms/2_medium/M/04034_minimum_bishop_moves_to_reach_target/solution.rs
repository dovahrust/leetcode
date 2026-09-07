impl Solution {
    pub fn min_bishop_moves(source: Vec<i32>, target: Vec<i32>) -> i32 {
        let (sx, sy) = (source[0], source[1]);
        let (tx, ty) = (target[0], target[1]);

        if sx == tx && sy == ty {
            return 0;
        }

        if ((sx + sy) & 1) != ((tx + ty) & 1) {
            return -1;
        }

        if (tx - sx).abs() == (ty - sy).abs() {
            return 1;
        }

        2
    }
}
