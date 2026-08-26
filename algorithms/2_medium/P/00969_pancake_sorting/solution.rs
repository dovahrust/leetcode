impl Solution {
    pub fn pancake_sort(mut arr: Vec<i32>) -> Vec<i32> {
        let len = arr.len();
        let mut res: Vec<i32> = Vec::new();

        for i in (0..len).rev() {
            let mut idx_max = 0;
            for j in 0..=i {
                if arr[j] >= arr[idx_max] {
                    idx_max = j;
                }
            }

            if idx_max != i {
                res.push(1 + idx_max as i32);
                arr[0..=idx_max].reverse();

                res.push(1 + i as i32);
                arr[0..=i].reverse();
            }
        }

        res
    }
}
