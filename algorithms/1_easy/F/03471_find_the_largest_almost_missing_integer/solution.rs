use std::collections::HashMap;

impl Solution {
    pub fn largest_integer(nums: Vec<i32>, k: i32) -> i32 {
        assert!(k >= 1 && (k as usize) <= nums.len());
        let len = nums.len();
        let k = k as usize;
        let mut res: Option<i32> = None;

        if k == len {
            res = Some(*nums.iter().max().unwrap());
        } else if k == 1 {
            let mut freqs: HashMap<i32, bool> = HashMap::new();

            for &num in &nums {
                *freqs.entry(num).and_modify(|x| *x = false).or_insert(true);
            }

            for (num, state) in freqs {
                if state {
                    res = match res {
                        None => Some(num),
                        Some(val) => Some(val.max(num)),
                    }
                }
            }
        } else {
            let (first, last) = (nums[0], nums[len - 1]);
            let (mut cnt_first, mut cnt_last) = (0, 0);

            for &num in &nums {
                if num == first {
                    cnt_first += 1;
                }

                if num == last {
                    cnt_last += 1;
                }
            }

            if cnt_first == 1 && cnt_last == 1 {
                res = Some(first.max(last));
            } else if cnt_first == 1 {
                res = Some(first);
            } else if cnt_last == 1 {
                res = Some(last);
            }
        }

        match res {
            None => -1,
            Some(val) => val,
        }
    }
}
