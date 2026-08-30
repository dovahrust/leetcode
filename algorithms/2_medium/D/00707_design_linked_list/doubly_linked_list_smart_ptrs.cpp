class MyLinkedList {
    struct Node {
        int val;
        shared_ptr<Node> next;
        weak_ptr<Node> prev;

        Node(int val) {
            this->val = val;
        }
    };

    size_t len;
    shared_ptr<Node> head;
    shared_ptr<Node> tail;
public:
    MyLinkedList() : len{ 0 }, head{ nullptr }, tail{ nullptr } {}
    
    int get(int index) const {
        const size_t from_left = static_cast<size_t>(index);
        if (from_left >= len) {
            return -1;
        }
        const size_t from_right = len - 1 - from_left;

        if (from_left <= from_right) {
            auto curr = head;
            for (size_t i{ 0 }; i < from_left; i += 1) {
                curr = curr->next;
            }
            return curr->val;
        } else {
            auto curr = tail;
            for (size_t i = 0; i < from_right; i += 1) {
                curr = curr->prev.lock();
            }
            return curr->val;
        }
    }
    
    void addAtHead(int val) {
        auto node = make_shared<Node>(val);
        if (!head) {
            head = node;
            tail = node;
        } else {
            head->prev = node;
            node->next = head;
            head = node;
        }

        len += 1;
    }
    
    void addAtTail(int val) {
        auto node = make_shared<Node>(val);
        if (!tail) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }

        len += 1;
    }
    
    void addAtIndex(int index, int val) {
        const size_t from_left = static_cast<size_t>(index);
        if (from_left > len) {
            return;
        }
        const size_t from_right = len - 1 - from_left;
        if (from_left == 0) {
            addAtHead(val);
        } else if (from_left == len) {
            addAtTail(val);
        } else if (from_left <= from_right) {
            auto curr = head;
            for (size_t i = 0; i < from_left; i += 1) {
                curr = curr->next;
            }
            auto node = make_shared<Node>(val);
            node->next = curr;
            node->prev = curr->prev;
            node->prev.lock()->next = node;
            curr->prev = node;

            len += 1;
        } else {
            auto curr = tail;
            for (size_t i = 0; i < from_right; i += 1) {
                curr = curr->prev.lock();
            }
            auto node = make_shared<Node>(val);
            node->next = curr;
            node->prev = curr->prev;
            node->prev.lock()->next = node;
            curr->prev = node;

            len += 1;
        }
    }
    
    void deleteAtIndex(const int index) {
        if (len == 0) {
            return;
        }

        const size_t from_left = static_cast<size_t>(index);
        if (from_left >= len) {
            return;
        }
        const size_t from_right = len - 1 - from_left;

        if (len == 1) {
            head = nullptr;
            tail = nullptr;
            len = 0;
        } else if (from_left == 0) {
            head = head->next;
            head->prev.reset();
            len -= 1;
        } else if (from_right == 0) {
            tail = tail->prev.lock();
            tail->next = nullptr;
            len -= 1;
        } else if (from_left <= from_right) {
            auto curr = head;
            for (size_t i = 0; i < from_left; ++i) {
                curr = curr->next;
            }
            auto next = curr->next;
            auto prev = curr->prev.lock();
            next->prev = prev;
            prev->next = next;
            len -= 1;
        } else {
            auto curr = tail;
            for (size_t i = 0; i < from_right; i += 1) {
                curr = curr->prev.lock();
            }
            auto next = curr->next;
            auto prev = curr->prev.lock();
            next->prev = prev;
            prev->next = next;
            len -= 1;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
