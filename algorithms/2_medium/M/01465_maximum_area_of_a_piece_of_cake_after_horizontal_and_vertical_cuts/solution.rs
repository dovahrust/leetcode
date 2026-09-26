impl Solution {
    const MOD: i64 = 1_000_000_007;

    fn calc_max(arr: &[i32], end: i32) -> i64 {
        let mut prev: i32 = 0;
        let mut max: i32 = 0;
        for &a in arr {
            max = max.max(a - prev);
            prev = a;
        }
        max = max.max(end - prev);

        max as i64
    }

    pub fn max_area(h: i32, w: i32, mut horizontal_cuts: Vec<i32>, mut vertical_cuts: Vec<i32>) -> i32 {
        horizontal_cuts.sort_unstable();
        vertical_cuts.sort_unstable();

        ((Self::calc_max(&horizontal_cuts, h) * Self::calc_max(&vertical_cuts, w)) % Self::MOD) as i32
    }
}
