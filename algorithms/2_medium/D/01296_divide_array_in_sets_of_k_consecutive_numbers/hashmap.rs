impl Solution {
    pub fn is_possible_divide(nums: Vec<i32>, k: i32) -> bool {
        assert!(k > 0 && !nums.is_empty());

        if k == 1 { return true; }

        if nums.len() % (k as usize) != 0 { return false; }

        use std::collections::HashMap;
        let mut map: HashMap<i32, usize> = HashMap::new();
        for num in nums {
            *map.entry(num).or_insert(0) += 1;
        }
        let mut uniques: Vec<i32> = map.keys().map(|x| *x).collect();
        uniques.sort_unstable();
        for beg in uniques {
            if let Some(&freq_beg) = map.get(&beg) && freq_beg != 0 {
                for u in beg..(beg + k) {
                    if let Some(freq) = map.get_mut(&u) {
                        if *freq < freq_beg {
                            return false;
                        }

                        *freq -= freq_beg;
                    } else {
                        return false;
                    }
                }
            }
        }

        true
    }
}
