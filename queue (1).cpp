#include<iostream>
using namespace std;
class queue{
    public:
        int front;
        int rear;
        int n;
        int arr[100];
        
        queue(){
            front = -1;
            rear = -1;
            cout<<"enter size of your queue: "<<endl;
            cin>>n;
            for(int i=0;i<n;i++){
                arr[i]=0;
            }
        }
        
        bool isempty(){
            if(front==-1 && rear==-1){
                return true;
            }
            else{
                return false;
            }
        }
        bool isfull(){
            if((rear+1)%n==front){
                return true;
            }
            else{
                return false;
            }
        }
        void enqueue(int value){
            if(isfull()){
                cout<<"cannot add more elements ";
                cout<<"queue is already full"<<endl;
                return;
            }
            else if(isempty()){
                rear=0;
                front=0;
                arr[rear]=value;
            }
            else{
                rear = (rear+1)%n;  
                arr[rear]=value;
            }
        }
        int dequeue(){
     
            if(isempty()){
                cout<<"cannot delete more elements ";
                cout<<"queue is already empty"<<endl;
                return 0;
            }
            else if(front==rear){
             // arr[front]=0;
              cout<<"deleted element is "<<arr[front]<<endl;
              arr[front]=0;
              front=-1; 
              rear=-1;
              return 0;
            }
            else{
                
                cout<<"deleted element is "<<arr[front]<<endl;
                arr[front]=0;
                front = (front+1)%n;
                return 0;
            }
        }
        void display(){
            //cout<<"Enter size of the queue"<<endl;
            for(int i=0;i<n;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
        
        void menu(){
            int ch,val;
            while(ch!=6){
                cout<<"enter 1 to add elements in queue"<<endl;
                cout<<"enter 2 to remove elements of queue"<<endl;
                cout<<"Enter 3 to display the queue"<<endl;
                cout<<"enter 4 to check empty"<<endl;
                cout<<"Enter 5 to check full"<<endl;
                cout<<"Enter 6 to exit"<<endl;
                cin>>ch;
                switch (ch)
                {
                case 1:
                    cout<<"enter element to add in the queue"<<endl;
                    cin>>val;
                    enqueue(val);
                    break;
                case 2:
                    cout<<"dequeue has started"<<endl;
                    dequeue();
                    break;
                case 3:
                    display();
                case 4:
                    if(isempty()){
                        cout<<"queue is empty"<<endl;
                    }
                    else{
                        cout<<"queue is not empty"<<endl;
                    }
                    break;
                case 5:
                    if(isfull()){
                        cout<<"queue is full"<<endl;
                    }
                    else{
                        cout<<"queue is not full"<<endl;
                    }
                    break;
                case 6:
                    exit(0);
                default:
                    cout<<"pls enter valid choice"<<endl;
                    break;
                }
            }
        }
            };
int main(){
    queue q;
    q.menu();
return 0;
}
