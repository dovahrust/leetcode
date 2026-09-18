struct NumArray {
    tree: Vec<i32>,
    n: usize,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl NumArray {
    fn dfs_init(tree: &mut [i32], idx: usize, lo: usize, hi: usize, nums: &[i32]) -> i32 {
        let res = if lo == hi { 
            nums[lo]
        } else {
            let mid = lo + (hi - lo) / 2;

            Self::dfs_init(tree, 2 * idx, lo, mid, nums) +
            Self::dfs_init(tree, 2 * idx + 1, mid + 1, hi, nums)
        };

        tree[idx] = res;
        res
    }

    fn new(nums: Vec<i32>) -> Self {
        assert!(!nums.is_empty());
        let len = nums.len();
        let mut tree: Vec<i32> = vec![0_i32; 4 * len];
        Self::dfs_init(&mut tree, 1, 0, len - 1, &nums);

        Self { tree, n: len }
    }

    fn update(&mut self, index: i32, val: i32) {
        debug_assert!(index >= 0 && (index as usize) < self.n);
        self.dfs_update(1, index as usize, 0, self.n - 1, val);
    }
    
    fn sum_range(&self, rlo: i32, rhi: i32) -> i32 {
        debug_assert!(rlo >= 0 && rlo <= rhi && (rhi as usize) < self.n);
        self.dfs_sum_range(1, 0, self.n - 1, rlo as usize, rhi as usize)
    }

    fn dfs_sum_range(&self, idx: usize, lo: usize, hi: usize, rlo: usize, rhi: usize) -> i32 {
        if lo == rlo && hi == rhi { return self.tree[idx]; }

        let mid = lo + (hi - lo) / 2;
        let mut res = 0_i32;
        if mid >= rlo {
            res += self.dfs_sum_range(2 * idx, lo, mid, rlo, rhi.min(mid));
        }

        if mid + 1 <= rhi {
            res += self.dfs_sum_range(2 * idx + 1, mid + 1, hi, (mid + 1).max(rlo), rhi);
        }

        res
    }

    fn dfs_update(&mut self, idx: usize, target_idx: usize, lo: usize, hi: usize, val: i32) {
        if hi == lo {
            self.tree[idx] = val;
        } else {
            let mid = lo + (hi - lo) / 2;
            if mid >= target_idx {
                self.dfs_update(2 * idx, target_idx, lo, mid, val);
            } else {
                self.dfs_update(2 * idx + 1, target_idx, mid + 1, hi, val);
            }

            self.tree[idx] = self.tree[2 * idx] + self.tree[2 * idx + 1];
        }
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * let obj = NumArray::new(nums);
 * obj.update(index, val);
 * let ret_2: i32 = obj.sum_range(left, right);
 */
