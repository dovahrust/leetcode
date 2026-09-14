use std::collections::HashMap;

struct Entity {
    is_ok: bool,
    prev_idx: usize,
    freqs: usize,
    first_width: Option<usize>,
}

impl Solution {
    pub fn count_special_integers(nums: Vec<i32>) -> i32 {
        let mut hashmap: HashMap<i32, Entity> = HashMap::new();

        for (i, num) in nums.into_iter().enumerate() {
            let entry = hashmap.entry(num).and_modify(|e| {
                if e.is_ok {
                    e.freqs += 1;
                    match e.first_width {
                        None => {
                            e.first_width = Some(i - e.prev_idx);
                        },
                        Some(width) => {
                            if i - e.prev_idx != width {
                                e.is_ok = false;
                            }
                        }
                    }

                    e.prev_idx = i;
                }
            }).or_insert( Entity {
                is_ok: true,
                prev_idx: i,
                freqs: 1,
                first_width: None,
            });
        }

        hashmap.into_iter().filter(|(_, e)| e.is_ok && e.freqs >= 3).count().try_into().unwrap()
    }
}
