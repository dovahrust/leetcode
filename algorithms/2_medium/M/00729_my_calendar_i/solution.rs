struct MyCalendar {
    arr: Vec<(i32, i32, isize, isize)>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyCalendar {

    fn new() -> Self {
        Self {
            arr: Vec::new()
        }
    }
    
    fn book(&mut self, start_time: i32, end_time: i32) -> bool {
        if self.arr.len() == 0 {
            self.arr.push((start_time, end_time, -1, -1));
            return true;
        }

        let mut curr_idx: usize = 0;
        loop {
            let (curr_st, curr_end, left, right) = self.arr[curr_idx];

            if end_time > curr_st && start_time < curr_end { return false; }

            let new_idx = if start_time < curr_st { left } else { right };

            if new_idx == -1 {
                if start_time < curr_st { 
                    self.arr[curr_idx].2 = self.arr.len() as isize;
                } else {
                    self.arr[curr_idx].3 = self.arr.len() as isize;
                }
                
                self.arr.push((start_time, end_time, -1, -1));
                return true;
            }

            curr_idx = new_idx as usize;
        }
    }
}

/**
 * Your MyCalendar object will be instantiated and called as such:
 * let obj = MyCalendar::new();
 * let ret_1: bool = obj.book(startTime, endTime);
 */
