impl Solution {
    pub fn uniform_array(nums1: Vec<i32>) -> bool {
        let (mut min, mut has_odd): (Option<i32>, bool) = (None, false);
        for num in nums1 {
            min = Some(min.unwrap_or(num).min(num));
            if (num & 1) == 1 {
                has_odd = true; 
            }
        }

        match min {
            Some(min_val) => {
                if (min_val & 1) == 0 && has_odd {
                    return false;
                }

                true
            },
            None => unreachable!(),
        }
    }
}
