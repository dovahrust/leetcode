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
use std::collections::HashMap;
impl Solution {
    fn dfs(preorder: &[i32], preorder_idx: usize, hashmap: &HashMap<i32, isize>, lo: isize, hi: isize) -> Option<Rc<RefCell<TreeNode>>> {
        if lo > hi {
            return None;
        }

        let node = Rc::new(RefCell::new(TreeNode::new(preorder[preorder_idx])));
        let i = *hashmap.get(&preorder[preorder_idx]).unwrap();
        node.borrow_mut().left = Self::dfs(preorder, preorder_idx + 1, hashmap, lo , i - 1);
        node.borrow_mut().right = Self::dfs(preorder, preorder_idx + (i - lo) as usize + 1, hashmap, i + 1 , hi);
        Some(node)
    }

    pub fn build_tree(preorder: Vec<i32>, inorder: Vec<i32>) -> Option<Rc<RefCell<TreeNode>>> {
        let len = preorder.len();
        let mut hashmap: HashMap<i32, isize> = HashMap::with_capacity(len * 2);
        for (i, v) in inorder.into_iter().enumerate() {
            hashmap.insert(v, i as isize);
        }
        if hashmap.len() != len {
            unreachable!("input values are not unique");
        }
        Self::dfs(&preorder, 0, &hashmap, 0, len as isize - 1)
    }
}
