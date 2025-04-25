class MyLinkedList {
    private:
        std::vector<int> data;
    
    public:
        MyLinkedList() {}
    
        int get(int index) {
            if (index < 0 || index >= data.size()) return -1;
            return data[index];
        }
    
        void addAtHead(int val) {
            data.insert(data.begin(), val);  
        }
    
        void addAtTail(int val) {
            data.push_back(val);  
        }
    
        void addAtIndex(int index, int val) {
            if (index < 0 || index > data.size()) return;
            data.insert(data.begin() + index, val);  
        }
    
        void deleteAtIndex(int index) {
            if (index < 0 || index >= data.size()) return;
            data.erase(data.begin() + index);
        }
    };
    