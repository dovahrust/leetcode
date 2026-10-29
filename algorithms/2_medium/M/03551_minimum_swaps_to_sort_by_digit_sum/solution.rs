impl Solution {
    const INVALID_SUM: i32 = -1;

    pub fn min_swaps(nums: Vec<i32>) -> i32 {
        let mut arr = nums.into_iter().enumerate().map(|(i, num)| {
            let mut sum: i32 = 0;
            let mut tmp: i32 = num;
            while tmp > 0 {
                sum += tmp % 10;
                tmp /= 10;
            };

            (sum, num, i)
        }).collect::<Vec<_>>();

        arr.sort_unstable();
        let len = arr.len();
        let mut total = len;

        for i in 0..len {
            if arr[i].0 != Self::INVALID_SUM {
                total -= 1;
                let mut j = i;
                while arr[j].0 != Self::INVALID_SUM {
                    arr[j].0 = Self::INVALID_SUM;
                    j = arr[j].2;
                }
            }
        }

        total as i32
    }
}
