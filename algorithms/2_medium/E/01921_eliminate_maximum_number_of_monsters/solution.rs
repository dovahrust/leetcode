impl Solution {
    pub fn eliminate_maximum(dist: Vec<i32>, speed: Vec<i32>) -> i32 {
        assert!(dist.len() == speed.len());
        let len = dist.len();

        let mut arr: Vec<i32> = Vec::with_capacity(len);
        for i in 0..len {
            assert!(speed[i] > 0);
            arr.push((dist[i] + speed[i] - 1) / speed[i]);
        }
        arr.sort_unstable();

        for i in 0..len {
            if (arr[i] as usize) < i + 1 {
                return i as i32;
            }
        }

        len as i32
    }
}
