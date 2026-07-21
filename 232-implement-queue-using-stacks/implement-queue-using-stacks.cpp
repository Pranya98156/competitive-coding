class MyQueue {
public:
int arr[100001];
int front;
int rear;
MyQueue(){
    front=0;
    rear=0;
}   
    void push(int x) {
        if(rear<100001) {
            arr[rear]=x;
            rear++;
        }      
    }

    int pop() {
        if(front==rear){
            return -1;
        }
        else{
            int ans=arr[front];
            arr[front]=-1;
            front++;
            if(front==rear){
                front=0;
                rear=0;
            }
            return ans;
        }
        
    }

    int peek() {
        if(front==rear){
            return -1;
        }
        else{
            return arr[front];
        }
    }

    bool empty() {
      if(front==rear){
        return true;
      }
      else{
        return false;
      }
    }
};