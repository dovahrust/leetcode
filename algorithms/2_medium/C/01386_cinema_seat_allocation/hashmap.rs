use std::collections::HashMap;

impl Solution {
    pub fn max_number_of_families(n: i32, reserved_seats: Vec<Vec<i32>>) -> i32 {
        debug_assert!(reserved_seats.len() <= 10_000 && n >= 1 && n <= 1_000_000_000);

        let mut hashmap: HashMap<i32, u16> = HashMap::new();

        for r in reserved_seats {
            debug_assert!(r[0] >= 1 && r[0] <= n && r[1] >= 1 && r[1] <= 10);

            if r[1] == 1 || r[1] == 10 {
                continue;
            }

            let curr_col = r[1] as u16;
            let mask = (1_u16 << (curr_col - 1)); 
            *hashmap.entry(r[0]).or_insert(0_u16) |= mask;
        }

        const LEFT: u16 = 0b_0_0001_1110;
        const RIGHT: u16 = 0b_1_1110_0000;
        const MID: u16 = 0b_0_0111_1000;
        let mut res = (n - hashmap.len() as i32) * 2;

        for (_, mask) in hashmap {
            if (mask & LEFT) == 0 && (mask & RIGHT) == 0 {
                res += 2;
            } else if (mask & LEFT) == 0 || (mask & RIGHT) == 0 || (mask & MID) == 0 {
                res += 1;
            }
        }

        res
    }
}
