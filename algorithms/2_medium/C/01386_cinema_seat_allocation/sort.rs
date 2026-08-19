impl Solution {
    pub fn max_number_of_families(n: i32, mut reserved_seats: Vec<Vec<i32>>) -> i32 {
        debug_assert!(reserved_seats.len() <= 10_000 && n >= 1 && n <= 1_000_000_000);

        reserved_seats.sort_unstable_by(|a, b| {
            if a[0] == b[0] {
                a[1].cmp(&b[1])
            } else {
                a[0].cmp(&b[0])
            }
        });

        let len = reserved_seats.len();
        let mut prev_row = 0_i32;
        let mut res = 0_i32;
        let mut idx = 0_usize;
        const LEFT: u32 = 0b_0_0001_1110;
        const RIGHT: u32 = 0b_1_1110_0000;
        const MID: u32 = 0b_0_0111_1000;

        while idx < len {
            let curr_row = reserved_seats[idx][0];
            res += (curr_row - 1 - prev_row) * 2;

            let mut seen = 0_u32;
            while idx < len && reserved_seats[idx][0] == curr_row {
                debug_assert!(reserved_seats[idx][1] >= 1 && reserved_seats[idx][1] <= 10);
                let curr_col = reserved_seats[idx][1] as u16;
                let mask = (1_u32 << (curr_col - 1));
                seen |= mask;
                idx += 1;
            }

            if (seen & LEFT) == 0 && (seen & RIGHT) == 0 {
                res += 2;
            } else if (seen & LEFT) == 0 || (seen & RIGHT) == 0 || (seen & MID) == 0 {
                res += 1;
            }

            prev_row = curr_row;
        }
        res += (n - prev_row) * 2;

        res
    }
}
