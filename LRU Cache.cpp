struct LinkNode{
    int val;
    int key;
    LinkNode * next;
    LinkNode * bf;
    LinkNode(int v,int k):val(v),key(k),next(NULL),bf(NULL){}
    LinkNode():val(0),key(0),next(NULL),bf(NULL){}
};

struct hashNode{
    LinkNode * now;
    bool flag;
    hashNode():flag(false),now(NULL){}
};

class LRUCache{
private:
    hashNode * hd;
    int len,size,cnt;
    LinkNode head;
    LinkNode tail;
public:
    const static int multi = 100;
    LRUCache(){
        hd = NULL;
        len = 0;
        size = 0;
        cnt = 0;
        head.bf = NULL;
        head.next = &tail;
        tail.next = NULL;
        tail.bf = &head;
    }

    LRUCache(int capacity) {
        len = capacity;
        size = len * multi;
        cnt = 0;
        hd = new hashNode[size];
        head.bf = NULL;
        head.next = &tail;
        tail.next = NULL;
        tail.bf = &head;
    }

    int locate(int key){
        int k = key % size;
        while( hd[k].flag && hd[k].now->key != key ) k = (k+1)%size;
        return k;
    }

    ~LRUCache(){
        if( hd!=NULL ) delete(hd);
        LinkNode * p=head.next;
        while(p!=&tail){
            delete p;
            p = p->next;
        }
    }

    void push( LinkNode* p ){
        p->next->bf = p->bf;
        p->bf->next = p->next;
        p->next = head.next;
        p->bf = &head;
        head.next = p;
        p->next->bf = p;
    }

    int get(int key) {
        if(len == 0) return -1;
        int rst = locate(key);
        if( !hd[rst].flag ) return -1;
        push(hd[rst].now);
        return hd[rst].now->val;
    }

    LinkNode * invalidate( ){
    //清除最后一个数据，并返回这个无效的地址。
        cnt--;
        LinkNode * last = tail.bf;
        last->bf->next = &tail;
        tail.bf = last->bf;
        return last;
    }

    void set(int key, int value) {
        if(len == 0) return;
        int rst = locate(key);
        if( !hd[rst].flag ){
            LinkNode * p;
            if( cnt == len ){
            //达到最大存储量
                p = invalidate();
                int tmp = locate( p->key );
                hd[tmp].flag = false;
                hd[tmp].now = NULL;
            }
            else{
                p = new LinkNode;
            }
            cnt++;
            p->key = key;
            p->val = value;
            p->next = head.next;
            p->bf = &head;
            head.next = p;
            p->next->bf = p;
            hd[rst].flag = true;
            hd[rst].now = p;
        }
        else{
            hd[rst].now -> val = value;
            push( hd[rst].now );
        }
    }
};