impl Solution {
    pub fn num_of_subarrays(arr: Vec<i32>, k: i32, threshold: i32) -> i32 {
        if k <= 0 || threshold < 0 { return -1; }

        let k = k as usize;
        let len = arr.len();
        if k > len { return 0; }

        let target = threshold * (k as i32);
        let mut cnt = 0_i32;
        let mut sum: i32 = arr[0..k].iter().sum();

        if sum >= target { cnt += 1; }

        for i in k..len {
            sum = sum + arr[i] - arr[i - k];

            if sum >= target { cnt += 1; }
        }

        cnt
    }
}
