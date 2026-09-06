struct MyQueue {
    put_stack: Vec<i32>,
    get_stack: Vec<i32>
}

impl MyQueue {

    fn new() -> Self {
        MyQueue {
            put_stack: Vec::new(),
            get_stack: Vec::new()
        }
    }

    fn fill_get_stack(&mut self) {
        if self.get_stack.is_empty() {
            while let Some(val) = self.put_stack.pop() {
                self.get_stack.push(val);
            }
        }
    }

    fn push(&mut self, x: i32) {
        self.put_stack.push(x);
    }

    fn pop(&mut self) -> i32 {
        self.fill_get_stack();
        self.get_stack.pop().unwrap()
    }

    fn peek(&mut self) -> i32 {
        self.fill_get_stack();
        *self.get_stack.last().unwrap()
    }

    fn empty(&self) -> bool {
        self.get_stack.is_empty() && self.put_stack.is_empty()
    }
}
