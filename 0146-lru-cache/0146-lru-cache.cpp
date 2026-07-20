class node{
    public:
    int key;
    int val;
    node* next;
    node* prev;

    node(int data1,int data2 ,node* next1,node* back1){
        key = data1;
        val = data2;
        next = next1;
        prev = back1;

    }
    node(int data1,int data2){
        key= data1;
        val = data2;
        next = nullptr;
        prev = nullptr;
        
    }
};
class LRUCache {
    map<int,node*>mpp;
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    int cap;
public:
    LRUCache(int capacity) {
        head->next = tail;
        tail->prev = head;
        cap = capacity;
    }
    void deletenode(node* delnode) {
        node* prevv = delnode->prev;
        node* nextt = delnode->next;

        prevv->next = nextt;
        nextt->prev = prevv;
    }

    void insertathead(node* newnode) {
        node* temp = head->next;

        head->next = newnode;
        newnode->prev = head;

        newnode->next = temp;
        temp->prev = newnode;
    }
    int get(int key) {
     if(mpp.find(key)==mpp.end()){
        return -1;
     }  
     else{
        node* newnode = mpp[key];
        deletenode(newnode);
        insertathead(newnode);
        return newnode->val;
     } 
    }
    
    void put(int key, int value) {
       if(mpp.find(key)!= mpp.end()){
        node* newnode = mpp[key];
        deletenode(newnode);
        insertathead(newnode);
        newnode->val = value;
       } 
       else{
        if(mpp.size()==cap){
            node* newnode = tail->prev;
            node* back = newnode->prev;
            mpp.erase(newnode->key);
            deletenode(newnode);
            back->next = tail;
            tail->prev = back;
        }
        node* newnode = new node(key,value);
        insertathead(newnode);
        mpp[key] = newnode;
       }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */