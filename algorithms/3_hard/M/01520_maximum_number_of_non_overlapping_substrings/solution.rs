impl Solution {
    const INF: usize = usize::MAX;

    pub fn max_num_of_substrings(s: String) -> Vec<String> {
        if s.is_empty() { return vec![]; }

        //               first      last   mask@last running_mask
        let mut seen = [(Self::INF, Self::INF, 0_u32, 0_u32); 26];
        let bytes = s.as_bytes();

        for (i, &b) in bytes.iter().enumerate() {
            debug_assert!(b >= b'a' && b <= b'z');
            let b_idx = (b - b'a') as usize;
            if seen[b_idx].0 == Self::INF {
                seen[b_idx].0 = i;
            }

            let mask = 1_u32 << (b_idx as u32);
            for j in 0..26 {
                if seen[j].0 != Self::INF {
                    seen[j].3 |= mask;
                }
            }
            seen[b_idx].1 = i;
            seen[b_idx].2 = seen[b_idx].3;
        }

        // Almost Bellman-Ford idea
        for _ in 0..26 {
            let mut has_update = false;
            for i in 0..26 {
                if seen[i].0 != Self::INF {
                    for j in 0..26 {
                        let mask_j = 1_u32 << (j as u32);
                        if (seen[i].2 & mask_j) != 0 {
                            if seen[j].0 < seen[i].0 {
                                has_update = true;
                                seen[i].0 = seen[j].0;
                            }

                            if seen[j].1 > seen[i].1 {
                                has_update = true;
                                seen[i].1 = seen[j].1;
                            }
                        }
                    }
                }
            }

            if !has_update {
                break;
            }
        }

        let mut res: Vec<String> = Vec::new();
        let mut valids: Vec<(usize, usize)> =  seen.iter().filter(|x| x.0 != Self::INF).map(|x| (x.0, x.1)).collect::<Vec<_>>();
        valids.sort_unstable_by_key(|x| x.1);
        res.push(String::from_utf8_lossy(&bytes[valids[0].0..=valids[0].1]).into_owned());

        let mut prev_end = valids[0].1;
        for (lo, hi) in valids.into_iter().skip(1) {
            if lo > prev_end {
                prev_end = hi;
                res.push(String::from_utf8_lossy(&bytes[lo..=hi]).into_owned());
            }
        }

        res
    }
}
