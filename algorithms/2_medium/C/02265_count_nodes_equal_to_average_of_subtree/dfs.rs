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
    fn dfs(node_rc_opt: Option<&Rc<RefCell<TreeNode>>>, res: &mut i32) -> (i32, i32) {
        if let Some(node_rc) = node_rc_opt {
            let node = node_rc.borrow();
            let (sum_l, cnt_l) = Self::dfs(node.left.as_ref(), res);
            let (sum_r, cnt_r) = Self::dfs(node.right.as_ref(), res);
            let sum = sum_l + sum_r + node.val;
            let cnt = cnt_l + cnt_r + 1;
            if node.val == sum / cnt {
                *res += 1;
            }

            return (sum, cnt);
        }

        (0, 0)
    }

    pub fn average_of_subtree(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut res = 0_i32;
        Self::dfs(root.as_ref(), &mut res);

        res
    }
}
