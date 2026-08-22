use std::cmp::Ordering;

impl Solution {
    fn dfs(width: i32, k: i32) -> bool {
        if width == 1 { return false; }

        let parent_width = width / 2;
        let mid = parent_width + 1;

        match k.cmp(&mid) {
            Ordering::Equal => true,
            Ordering::Less => Self::dfs(parent_width, k),
            Ordering::Greater => !Self::dfs(parent_width, parent_width - (k - mid - 1))
        }
    }

    pub fn find_kth_bit(n: i32, k: i32) -> char {
        assert!(n >= 1 && n <= 20);
        let width = (1 << n) - 1;
        assert!(k >= 1 && k <= width);

        if Self::dfs(width, k) {
            '1'
        } else {
            '0'
        }
    }
}
