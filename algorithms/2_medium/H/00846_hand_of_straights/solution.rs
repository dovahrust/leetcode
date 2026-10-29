impl Solution {
    pub fn is_n_straight_hand(hand: Vec<i32>, group_size: i32) -> bool {
        assert!(group_size > 0 && !hand.is_empty());

        if group_size == 1 { return true; }

        if hand.len() % (group_size as usize) != 0 { return false; }

        use std::collections::HashMap;
        let mut map: HashMap<i32, usize> = HashMap::new();
        for num in hand {
            *map.entry(num).or_insert(0) += 1;
        }
        let mut uniques: Vec<i32> = map.keys().map(|x| *x).collect();
        uniques.sort_unstable();
        for beg in uniques {
            if let Some(&freq_beg) = map.get(&beg) && freq_beg != 0 {
                for u in beg..(beg + group_size) {
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
