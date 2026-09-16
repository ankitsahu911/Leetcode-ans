class Solution {
public:
    Node* connect(Node* root) {
        Node* curr = root;

        while (curr != nullptr) {
            Node dummy(0);
            Node* tail = &dummy;

            while (curr != nullptr) {
                if (curr->left != nullptr) {
                    tail->next = curr->left;
                    tail = tail->next;
                }
                if (curr->right != nullptr) {
                    tail->next = curr->right;
                    tail = tail->next;
                }
                curr = curr->next;
            }

            curr = dummy.next;
        }

        return root;
    }
};