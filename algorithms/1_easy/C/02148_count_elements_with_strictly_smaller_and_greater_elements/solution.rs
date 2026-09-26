impl Solution {
    pub fn count_elements(nums: Vec<i32>) -> i32 {
        let mut min = i32::MAX;
        let mut max = i32::MIN;
        let mut min_cnt: usize = 0;
        let mut max_cnt: usize = 0;
        let len = nums.len();

        for num in nums {
            if min > num {
                min = num;
                min_cnt = 1;
            } else if min == num {
                min_cnt += 1;
            }

            if max < num {
                max = num;
                max_cnt = 1;
            } else if max == num {
                max_cnt += 1;
            }
        }

        if min == max {
            return 0;
        }

        (len - max_cnt - min_cnt).try_into().unwrap()
    }
}
