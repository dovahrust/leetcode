struct Data {
    curr: i32,
    a: u8,
    b: u8,
    k: i32,
}

impl Data {
    #[inline(always)]
    fn new(a: u8, b:u8, k: i32) -> Self {
        Self { curr: 0, a: a, b: b, k: k }
    }

    #[inline(always)]
    fn add(&mut self, byte: u8) {
        if byte == self.a || byte == self.b {
            self.curr += 1;
        } else if self.k > 0 {
            self.k -= 1;
            self.curr += 1;
        } else {
            self.curr -= 1;
        }
    }
}

impl Solution {
    pub fn max_distance(s: String, k: i32) -> i32 {
        assert!(s.len() <= 100_000);

        let mut max = 0_i32;
        let mut ne = Data::new(b'N', b'E', k);
        let mut nw = Data::new(b'N', b'W', k);
        let mut se = Data::new(b'S', b'E', k);
        let mut sw = Data::new(b'S', b'W', k);

        for &byte in s.as_bytes() {
            ne.add(byte);
            nw.add(byte);
            se.add(byte);
            sw.add(byte);

            max = max.max(ne.curr).max(nw.curr).max(sw.curr).max(se.curr);
        }

        max
    }
}
