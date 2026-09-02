impl Solution {
    fn dfs(arr: &[i32], used: &mut [bool], tmp: &mut [i32; 4], tmp_idx: usize, largest: &mut Option<(i32, i32)>) {
        if tmp_idx == 4 {
            let (h, m) = (tmp[0] * 10 + tmp[1], tmp[2] * 10 + tmp[3]);
            if h < 24 && m < 60 {
                *largest = Some(largest.unwrap_or((h, m)).max((h, m)));
            }
            return;
        }

        for i in 0..4 {
            if !used[i] {
                used[i] = true;
                tmp[tmp_idx] = arr[i];
                Self::dfs(arr, used, tmp, tmp_idx + 1, largest);
                used[i] = false;
            }
        }
    }

    pub fn largest_time_from_digits(arr: Vec<i32>) -> String {
        debug_assert!(arr.len() == 4 && arr.iter().all(|&x| x >= 0 && x <= 9));
        let mut tmp = [0_i32; 4];
        let mut largest: Option<(i32, i32)> = None;
        let mut used = [false; 4];

        Self::dfs(&arr, &mut used, &mut tmp, 0, &mut largest);

        largest.map_or_else(String::new, |(h, m)| format!("{:02}:{:02}", h, m))
    }
}
