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
    fn dfs(node_rc_opt: Option<Rc<RefCell<TreeNode>>>, lo: i32, hi: i32) -> Option<Rc<RefCell<TreeNode>>> {
        if let Some(node_rc) = node_rc_opt {
            let mut node = node_rc.borrow_mut();
            let left = node.left.take();
            let right = node.right.take();

            if node.val > hi {
                return Self::dfs(left, lo, hi);
            } if node.val < lo {
                return Self::dfs(right, lo, hi);
            } else {
                node.left = Self::dfs(left, lo, hi);
                node.right = Self::dfs(right, lo, hi);
                drop(node);
                return Some(node_rc);
            }
        }

        None
    }

    pub fn trim_bst(root: Option<Rc<RefCell<TreeNode>>>, lo: i32, hi: i32) -> Option<Rc<RefCell<TreeNode>>> {
        Self::dfs(root, lo, hi)
    }
}
