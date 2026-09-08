// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    fn dfs_h_left(curr_node_rc_opt: Option<&Rc<RefCell<TreeNode>>>) -> u32 {
        if let Some(curr_node_rc) = curr_node_rc_opt {
            let curr_node = curr_node_rc.borrow();
            return 1 + Self::dfs_h_left(curr_node.left.as_ref());
        }

        0
    }

    fn dfs_does_exist(curr_node_rc_opt: Option<&Rc<RefCell<TreeNode>>>, mid: u32,  mask: u32) -> bool {
        if let Some(curr_node_rc) = curr_node_rc_opt {
            if mask == 0 {
                return true;
            }

            let curr_node = curr_node_rc.borrow();
            if (mask & mid) == 0 {
                return Self::dfs_does_exist(curr_node.left.as_ref(), mid, mask >> 1);
            } else {
                return Self::dfs_does_exist(curr_node.right.as_ref(), mid, mask >> 1);
            }
        }

        false
    }

    pub fn count_nodes(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        if root.is_none() { return 0; }       

        let h_left = Self::dfs_h_left(root.as_ref());

        if h_left == 1 { return 1; }

        let base = 2_u32.pow(h_left - 1) - 1;
        let extra = base + 1;

        let mut lo = 0;
        let mut hi = extra - 1;
        let mask = 1_u32 << (h_left - 2);

        while lo <= hi {
            let mid = lo + (hi - lo) / 2;
            if Self::dfs_does_exist(root.as_ref(), mid, mask) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        (base + lo).try_into().unwrap()
    }
}
