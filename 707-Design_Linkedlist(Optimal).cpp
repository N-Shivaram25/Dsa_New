class MyLinkedList {
    private:
        struct Node {
            int val;
            Node* prev;
            Node* next;
            Node(int v) : val(v), prev(nullptr), next(nullptr) {}
        };
    
        Node* head; 
        Node* tail; 
        int size;
    
    public:
        MyLinkedList() {
            head = new Node(0);
            tail = new Node(0);
            head->next = tail;
            tail->prev = head;
            size = 0;
        }
    
        int get(int index) {
            if (index < 0 || index >= size)
                return -1;
            Node* curr;
            if (index + 1 < size - index) {
                curr = head->next;
                for (int i = 0; i < index; ++i)
                    curr = curr->next;
            } else {
                curr = tail->prev;
                for (int i = 0; i < size - index - 1; ++i)
                    curr = curr->prev;
            }
            return curr->val;
        }
    
        void addAtHead(int val) { addAtIndex(0, val); }
    
        void addAtTail(int val) { addAtIndex(size, val); }
    
        void addAtIndex(int index, int val) {
            if (index < 0 || index > size)
                return;
            Node* pred;
            Node* succ;
    
            if (index < size - index) {
                pred = head;
                for (int i = 0; i < index; ++i)
                    pred = pred->next;
                succ = pred->next;
            } else {
                succ = tail;
                for (int i = 0; i < size - index; ++i)
                    succ = succ->prev;
                pred = succ->prev;
            }
    
            Node* newNode = new Node(val);
            newNode->prev = pred;
            newNode->next = succ;
            pred->next = newNode;
            succ->prev = newNode;
            size++;
        }
    
        void deleteAtIndex(int index) {
            if (index < 0 || index >= size)
                return;
            Node* curr;
            if (index < size - index) {
                curr = head->next;
                for (int i = 0; i < index; ++i)
                    curr = curr->next;
            } else {
                curr = tail->prev;
                for (int i = 0; i < size - index - 1; ++i)
                    curr = curr->prev;
            }
    
            Node* pred = curr->prev;
            Node* succ = curr->next;
            pred->next = succ;
            succ->prev = pred;
            delete curr;
            size--;
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