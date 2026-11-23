struct ProductOfNumbers {
    nums: Vec<i32>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl ProductOfNumbers {

    fn new() -> Self {
        Self {
            nums: Vec::new(),
        }
    }
    
    fn add(&mut self, num: i32) {
        if num == 0 {
            self.nums.clear();
        } else {
            let last = *self.nums.last().unwrap_or(&1);
            self.nums.push(last * num);
        }
    }
    
    fn get_product(&self, k: i32) -> i32 {
        debug_assert!(k >= 1);
        let k = k as usize;
        let len = self.nums.len();

        if k > len { return 0; }

        let last = *self.nums.last().unwrap();
        let before_k = if k == len { 1 } else { self.nums[len - k - 1] };

        last / before_k
    }
}

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * let obj = ProductOfNumbers::new();
 * obj.add(num);
 * let ret_2: i32 = obj.get_product(k);
 */
