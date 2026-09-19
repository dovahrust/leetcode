const N: usize = 5;
const VALS: [i32; N] = [20, 50, 100, 200, 500];

struct ATM {
    arr: [i32; N],
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl ATM {
    fn new() -> Self {
        Self {
            arr: [0; N],
        }
    }

    fn deposit(&mut self, banknotes_count: Vec<i32>) {
        for i in 0..N {
            self.arr[i] += banknotes_count[i];
        }
    }

    fn withdraw(&mut self, mut amount: i32) -> Vec<i32> {
        let mut res = [0_i32; N];
        for i in (0..N).rev() {
            let cnt = (amount / VALS[i]).min(self.arr[i]);
            amount -= cnt * VALS[i];
            res[i] = cnt;
        }

        if amount != 0 {
            return vec![-1];
        }

        for i in 0..N {
            self.arr[i] -= res[i];
        }

        res.into_iter().collect()
    }
}

/**
 * Your ATM object will be instantiated and called as such:
 * let obj = ATM::new();
 * obj.deposit(banknotesCount);
 * let ret_2: Vec<i32> = obj.withdraw(amount);
 */
