impl Solution {
    pub fn peak_index_in_mountain_array(arr: Vec<i32>) -> i32 {
        let len = arr.len() as isize;
        assert!(len >= 3);
        let mut hi = len - 1;
        let mut lo = 0_isize;

        while lo <= hi {
            let mid = lo + (hi - lo) / 2;
            if mid == len - 1 { unreachable!("invalid input"); }

            if arr[mid as usize + 1] > arr[mid as usize] {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        lo.try_into().unwrap()
    }
}
