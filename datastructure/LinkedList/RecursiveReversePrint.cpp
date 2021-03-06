/*
    print Linked List in reverse order recursively
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

typedef struct node *node_ptr;

typedef struct node {
    int data;
    node_ptr next;
};

typedef node_ptr LIST;
typedef node_ptr position;

class LinkedList {
    private:
        int count;
        LIST head;
    
    public:
        LinkedList() {
            count = 0;
            head = NULL;
        }
        
        void push(int val) {
            //position p = (LIST)malloc(sizeof(struct node));
            position p = new node[1];
            
            p->data = val;
            p->next = head;
            
            head = p;
            count++;
        }    
            
        void deleteElement(int index) {
            position p = head;
            position temp;
            
            if(index > count) {
                cout<<"Out of range.\nPlease select a value under "<<count<<endl;
                return;
            }   
            
            for(int i=0;i<index-1;i++) {
                p = p->next;
            }
            
            temp = p;
            temp = temp->next;
            
            p->next = temp->next;
            
            free(temp);
            
            count--;    
        }    
        
        void deleteAll() {
            position p = head;
            
            while(head != NULL) {
                head = head->next;
                free(p);
                p = head;    
                count--;
            }    
        }    
        
        int length() {
            return count;
        }    
        
        void reverse() {
            position p,temp;
            p = head;
            temp = NULL;
            
            while(head) {
                p = head->next;
                head->next = temp;
                temp = head;
                head = p;
            }    
            
            head = temp;
        }    
        
        void print() {
            position p = head;
            
            while(p != NULL) {
                cout<<p->data<<" ";
                p = p->next;
            }    
            
            cout<<endl;
        }
        
        void printInReverseOrder() {
            position p = head;
            doReversePrint(p);
            cout<<endl;
        }            
        
        void doReversePrint(LIST p) {
            if(p == NULL) return;
            doReversePrint(p->next);
            cout<<p->data<<" "; 
        }    
};    

int main() {
    LinkedList list;
    list.push(1);
    list.push(2);
    list.push(3);
    
    list.print();
    
    list.reverse();
    
    list.print();
    
    list.printInReverseOrder();
    
    system("pause");
    return 0;
}    
