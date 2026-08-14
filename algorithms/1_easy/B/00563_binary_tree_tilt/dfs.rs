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
    fn dfs(node_rc_opt: Option<&Rc<RefCell<TreeNode>>>, res: &mut i32) -> i32 {
        if let Some(node_rc) = node_rc_opt {
            let node = node_rc.borrow();
            let left_sum = Self::dfs(node.left.as_ref(), res);
            let right_sum = Self::dfs(node.right.as_ref(), res);

            *res += (left_sum - right_sum).abs();

            return left_sum + node.val + right_sum;
        }

        0
    }

    pub fn find_tilt(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut res = 0_i32;

        Self::dfs(root.as_ref(), &mut res);

        res
    }
}
