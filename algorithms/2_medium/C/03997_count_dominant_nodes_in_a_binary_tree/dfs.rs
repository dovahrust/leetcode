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
    fn dfs(node_rc_opt: Option<&Rc<RefCell<TreeNode>>>, cnt: &mut i32) -> i32 {
        match node_rc_opt {
            None => i32::MIN,
            Some(node_rc) => {
                let node = node_rc.borrow();
                let val = node.val;
                let lval = Self::dfs(node.left.as_ref(), cnt);
                let rval = Self::dfs(node.right.as_ref(), cnt);
                let mval = val.max(lval).max(rval);

                if val == mval {
                    *cnt += 1;
                }

                mval
            }
        }
    }

    pub fn count_dominant_nodes(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut cnt = 0_i32;
        Self::dfs(root.as_ref(), &mut cnt);
        cnt
    }
}
