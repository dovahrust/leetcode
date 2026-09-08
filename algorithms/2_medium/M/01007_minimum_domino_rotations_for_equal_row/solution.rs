impl Solution {
    #[inline(always)]
    fn calc(val: i32, tops: &[i32], bottoms: &[i32]) -> Option<usize> {
        let len = tops.len();
        let (mut need_top, mut need_bottom) = (0_usize, 0_usize);
        for i in 0..len {
            if tops[i] != val && bottoms[i] != val {
                return None;
            }

            if tops[i] != val {
                need_top += 1;
            }

            if bottoms[i] != val {
                need_bottom += 1;
            }
        }

        Some(need_top.min(need_bottom))
    }

    pub fn min_domino_rotations(tops: Vec<i32>, bottoms: Vec<i32>) -> i32 {
        assert!(!tops.is_empty() && tops.len() == bottoms.len());

        let cost_top_first = Self::calc(tops[0], &tops, &bottoms);
        let cost_bottom_first = Self::calc(bottoms[0], &tops, &bottoms);

        match (cost_top_first, cost_bottom_first) {
            (None, None) => -1,
            (Some(val1), None) => val1.try_into().unwrap(),
            (None, Some(val2)) => val2.try_into().unwrap(),
            (Some(val1), Some(val2)) => val1.min(val2).try_into().unwrap(),
        }
    }
}
