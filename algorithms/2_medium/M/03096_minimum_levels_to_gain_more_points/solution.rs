impl Solution {
    pub fn minimum_levels(possible: Vec<i32>) -> i32 {
        assert!(possible.len() > 1);

        let len = possible.len();
        let mut pref: i32 = 0;
        let mut suff: i32 = 0;

        for &p in &possible {
            if p == 1 {
                suff += 1;
            } else {
                suff -= 1;
            }
        }

        for i in 0..(len - 1) {
            let p = possible[i];

            if p == 1 {
                pref += 1;
                suff -= 1;
            } else {
                pref -= 1;
                suff += 1;
            }

            if pref > suff {
                return (i + 1).try_into().unwrap();
            }
        }

        -1
    }
}
