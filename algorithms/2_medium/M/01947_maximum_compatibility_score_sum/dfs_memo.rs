const INF: u32 = u32::MAX;

impl Solution {
    fn dfs(
        s: &[u8],
        s_idx: usize,
        m: &[u8],
        seen: u8,
        cols_flag: u8,
        memo: &mut [u32]
    ) -> u32 {
        if memo[seen as usize] != INF {
            return memo[seen as usize];
        }

        let len = s.len();

        if len == s_idx {
            return 0;
        }

        let mut max = 0;
        for i in 0..len {
            let flag = 1_u8 << (i as u8);
            if seen & flag == 0 {
                let score = ((!(s[s_idx] ^ m[i])) & cols_flag).count_ones();
                max = max.max(score + Self::dfs(s, s_idx + 1, m, seen | flag, cols_flag, memo));
            }
        }

        memo[seen as usize] = max;
        max
    }

    fn into_bitmask(arr: Vec<Vec<i32>>) -> Vec<u8> {
        let mut res: Vec<u8> = Vec::with_capacity(arr.len());
        for a in arr {
            assert!(a.len() <= 8);
            let mut mask = 0_u8;
            for (i, v) in a.into_iter().enumerate() {
                match v {
                    0 => {},
                    1 => mask |= (1_u8 << (i as u8)),
                    _ => unreachable!("invalid input")
                }
            }
            res.push(mask);
        }
        res
    }

    pub fn max_compatibility_sum(students: Vec<Vec<i32>>, mentors: Vec<Vec<i32>>) -> i32 {
        assert!(mentors.len() > 0 && mentors.len() <= 8 && students.len() == mentors.len());
        let cols = mentors[0].len();
        assert!(cols >=1 && cols <= 8);
        assert!((0..students.len()).into_iter().all(|i| students[i].len() == cols &&  mentors[i].len() == cols));

        let cols_flag = ((1_usize << cols) - 1) as u8;
        let s = Self::into_bitmask(students);
        let m = Self::into_bitmask(mentors);
        let mut memo: Vec<u32> = vec![INF; 2_usize.pow(m.len() as u32)];
        let (s_idx, seen) = (0_usize, 0_u8);

        Self::dfs(&s, s_idx, &m, seen, cols_flag, &mut memo).try_into().unwrap()
    }
}
