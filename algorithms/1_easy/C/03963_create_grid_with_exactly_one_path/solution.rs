impl Solution {
    pub fn create_grid(m: i32, n: i32) -> Vec<String> {
        let mut res: Vec<String> = Vec::with_capacity(m as usize);
        res.push(String::from_utf8(vec![b'.'; n as usize]).unwrap());
        let mut tmp = vec![b'#'; n as usize];
        tmp[(n - 1) as usize] = b'.';
        for _ in 1..m {
            res.push(String::from_utf8(tmp.clone()).unwrap());
        }

        res
    }
}
