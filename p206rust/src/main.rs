struct Solution;

// Definition for singly-linked list.
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>
}

impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode {
        next: None,
        val
        }
    }

    #[inline]
    fn new_with_node(val: i32, node: Box<ListNode>) -> Self {
        ListNode {
            next: Some(node),
            val
        }
    }
}

impl Solution {
    pub fn reverse_list(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        if head == None {
            return None;
        }

        let mut prev: Option<Box<ListNode>> = None;
        let mut current: Option<Box<ListNode>> = head;

        while let Some(mut node) = current {
            current = node.next;
            node.next = prev;
            prev = Some(node);
        }

        prev
    }
}

fn main() {
    let a: ListNode = ListNode::new(5);
    let b: ListNode = ListNode::new_with_node(4, Box::new(a));
    let c: ListNode = ListNode::new_with_node(3, Box::new(b));
    let d: ListNode = ListNode::new_with_node(2, Box::new(c));
    let e: ListNode = ListNode::new_with_node(1, Box::new(d));

    let mut x = Solution::reverse_list(Some(Box::new(e)));
    while let Some(i) = x{
        print!("{} ", i.val);
        x = i.next;
    }
}
