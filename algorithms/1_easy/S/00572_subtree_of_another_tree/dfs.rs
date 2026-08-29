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
    fn dfs_both(
        root: Option<&Rc<RefCell<TreeNode>>>,
        sub_root: Option<&Rc<RefCell<TreeNode>>>
    ) -> bool {
        match (root, sub_root) {
            (None, None) => true,
            (None, Some(_)) | (Some(_), None) => false,
            (Some(r_rc), Some(s_rc)) => {
                let r = r_rc.borrow();
                let s = s_rc.borrow();

                r.val == s.val &&
                Self::dfs_both(r.left.as_ref(), s.left.as_ref()) &&
                Self::dfs_both(r.right.as_ref(), s.right.as_ref())
            },
        }
    }

    fn dfs_root(
        root: Option<&Rc<RefCell<TreeNode>>>,
        sub_root: Option<&Rc<RefCell<TreeNode>>>
    ) -> bool {
        if root.is_none() { return false; }

        Self::dfs_both(root, sub_root) ||
        Self::dfs_root(root.unwrap().borrow().left.as_ref(), sub_root) ||
        Self::dfs_root(root.unwrap().borrow().right.as_ref(), sub_root)
    }

    pub fn is_subtree(
        root: Option<Rc<RefCell<TreeNode>>>,
        sub_root: Option<Rc<RefCell<TreeNode>>>
    ) -> bool {
        assert!(root.is_some() && sub_root.is_some());

        Self::dfs_root(root.as_ref(), sub_root.as_ref())
    }
}
