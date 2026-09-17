use std::collections::HashMap;

struct RangeFreqQuery {
    map: HashMap<i32, Vec<usize>>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl RangeFreqQuery {

    fn new(arr: Vec<i32>) -> Self {
        let mut map: HashMap<i32, Vec<usize>> = HashMap::new();
        for (i, a) in arr.into_iter().enumerate() {
            map.entry(a).or_insert(Vec::new()).push(i);
        }
        Self {
            map: map,
        }
    }
    
    fn query(&self, left: i32, right: i32, val: i32) -> i32 {
        if let Some(v) = self.map.get(&val) {
            let (left, right) = (left as usize, right as usize);
            let lb = v.partition_point(|x| *x < left);
            let ub = v.partition_point(|x| *x <= right);

            return (ub - lb).try_into().unwrap();
        }

        0
    }
}

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * let obj = RangeFreqQuery::new(arr);
 * let ret_1: i32 = obj.query(left, right, value);
 */
