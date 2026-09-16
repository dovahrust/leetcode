impl Solution {
    pub fn maximum_bags(capacity: Vec<i32>, rocks: Vec<i32>, mut additional_rocks: i32) -> i32 {
        let n = capacity.len();
        let mut needs: Vec<i32> = Vec::with_capacity(n);

        for i in 0..n {
            needs.push(capacity[i] - rocks[i]);
        } 

        needs.sort_unstable();

        let mut cnt: usize = 0;
        for need in needs {
            if need > additional_rocks {
                break;
            }

            additional_rocks -= need;
            cnt += 1;
        }

        cnt.try_into().unwrap()
    }
}
