#[derive(Clone, Copy)]
struct Frac {
    n: i32,
    d: i32,
}

impl Default for Frac {
    #[inline(always)]
    fn default() -> Self {
        Self { n: 0, d: 1 }
    }
}

impl Frac {
    #[inline(always)]
    fn is_24(&self) -> bool {
        self.d != 0 && self.n == 24 * self.d
    }

    #[inline(always)]
    fn mul(&self, other: Self) -> Self {
        Self { n: self.n * other.n, d: self.d * other.d }
    }

    #[inline(always)]
    fn div(&self, other: Self) -> Option<Self> {
        if other.n == 0 { return None; }

        Some(Self { n: self.n * other.d, d: self.d * other.n })
    }

    #[inline(always)]
    fn add(&self, other: Self) -> Self {
        Self { n: self.n * other.d + other.n * self.d, d: self.d * other.d }
    }

    #[inline(always)]
    fn sub(&self, other: Self) -> Self {
        Self { n: self.n * other.d - other.n * self.d, d: self.d * other.d }
    }
}

impl Solution {
    const CARDS_EXACT_LEN: usize = 4;

    fn dfs(
        cards: &[Frac; Self::CARDS_EXACT_LEN],
        n: usize,
    ) -> bool {
        if n == 1 { return cards[0].is_24(); }

        let mut next = [Frac::default(); Self::CARDS_EXACT_LEN];

        for i in 0..n {
            for j in (i + 1)..n {
                let mut next_idx = 0_usize;
                for k in 0..n {
                    if k != i && k != j {
                        next[next_idx] = cards[k];
                        next_idx += 1;
                    }
                }

                let (a, b) = (cards[i], cards[j]);

                for op in 0..6 {
                    next[next_idx] = match op {
                        0 => a.mul(b),
                        1 => {
                            match a.div(b) {
                                Some(v) => v,
                                None => continue,
                            }
                        },
                        2 => a.add(b),
                        3 => a.sub(b),
                        4 => {
                            match b.div(a) {
                                Some(v) => v,
                                None => continue,
                            }
                        },
                        5 => b.sub(a),
                        _ => unreachable!(),
                    };

                    if Self::dfs(&next, next_idx + 1) {
                        return true;
                    }
                }
            }
        }

        false
    }

    pub fn judge_point24(cards_vec: Vec<i32>) -> bool {
        assert!(cards_vec.len() == Self::CARDS_EXACT_LEN);

        let mut cards = [
            Frac { n: cards_vec[0], d: 1 },
            Frac { n: cards_vec[1], d: 1 },
            Frac { n: cards_vec[2], d: 1 },
            Frac { n: cards_vec[3], d: 1 },
        ];

        Self::dfs(&mut cards, Self::CARDS_EXACT_LEN)
    }
}
