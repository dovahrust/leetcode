impl Solution {
    pub fn max_dist_to_closest(seats: Vec<i32>) -> i32 {
        assert!(seats.iter().any(|&seat| seat == 0));
        assert!(seats.iter().any(|&seat| seat == 1));

        let len = seats.len();
        let mut prev: Option<usize> = None;
        let mut res = 0_usize;
        for (i, seat) in seats.into_iter().enumerate() {
            assert!(seat == 0 || seat == 1);

            if seat == 1 {
                match prev {
                    None => res = i,
                    Some(other) => res = res.max((i - other) / 2),
                }
                prev = Some(i);
            }
        }
        res = res.max(len - 1 - prev.unwrap());

        res.try_into().unwrap()
    }
}
