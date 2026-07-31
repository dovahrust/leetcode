impl Solution {
    pub fn xor_queries(arr: Vec<i32>, queries: Vec<Vec<i32>>) -> Vec<i32> {
        let arr_len = arr.len();
        let mut prefix = vec![0_i32; arr_len + 1];
        for (i, a) in arr.into_iter().enumerate() {
            prefix[i + 1] = prefix[i] ^ a;
        }
        let mut res: Vec<i32> = Vec::with_capacity(queries.len());

        for query in queries {
            assert!(query.len() == 2);
            let lo = query[0];
            let hi = query[1];
            assert!(lo >= 0 && hi >= lo && (hi as usize) < arr_len);
            res.push(prefix[hi as usize + 1] ^ prefix[lo as usize]);
        }

        res
    }
}
