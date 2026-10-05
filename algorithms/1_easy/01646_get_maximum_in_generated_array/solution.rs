impl Solution {
    pub fn get_maximum_generated(n: i32) -> i32 {
        if n == 0 { return 0; }

        let n = n as usize;
        let mut arr = vec![0_i32; n + 1];
        arr[1] = 1;
        for i in 2..=n {
            if (i & 1) == 1 {
                arr[i] = arr[i / 2] + arr[(i / 2) + 1];
            } else {
                arr[i] = arr[i / 2];
            }
        }

        arr.into_iter().max().unwrap()
    }
}
