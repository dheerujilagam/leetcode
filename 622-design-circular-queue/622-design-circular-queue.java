class MyCircularQueue {
    class ListNode{
        int val;
        ListNode next;
        ListNode(int x){
            val=x;
            next=null;
        }
    }
    int cursize=0,maxsize;
    ListNode r=null,f=null;
    
    public MyCircularQueue(int k) {
        maxsize=k;
    }
    
    public boolean enQueue(int value) {
        if(cursize<maxsize){
            ListNode newnode = new ListNode(value);
            if(f==null){
                f=newnode;
                r=newnode;
            }
            else{
                r.next=newnode;
                r=r.next;
            }
            cursize++;
            return true;
        }
        return false;
    }
    
    public boolean deQueue() {
        if(f!=null){
            ListNode temp = f;
            f=f.next;
            temp.next=null;
            cursize--;
            return true;
        }
        return false;
    }
    
    public int Front() {
        if(cursize==0)
            return -1;
        return f.val;
    }
    
    public int Rear() {
        if(cursize==0)
            return -1;
        return r.val;
    }
    
    public boolean isEmpty() {
        return cursize==0;
    }
    
    public boolean isFull() {
        return maxsize==cursize;
    }
}

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * boolean param_1 = obj.enQueue(value);
 * boolean param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * boolean param_5 = obj.isEmpty();
 * boolean param_6 = obj.isFull();
 */