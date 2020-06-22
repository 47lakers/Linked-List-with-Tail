//
//  main.cpp
//  Linked List with a Tail
//
//  Created by Ira Xavier Porchia on 5/9/20.
//  Copyright © 2020 Ira Xavier Porchia. All rights reserved.
//

#include <iostream>
using namespace std;

class node{
    friend class circular;
private:
    int _data;
    node *_next;
public:
    node(int data):
    _data(data),
    _next(nullptr){}
};

class circular{
private:
    node *_head;
    node *_tail;
public:
    circular():
    _head(nullptr),
    _tail(nullptr){}
    
    ~circular(){
        clear();
    }
    
    void clear(){
        node *temp;
        _tail = nullptr;
        while(_head != nullptr){
            temp = _head;
            _head = _head->_next;
            temp->_next = nullptr;
            delete temp;
        }
    }
    
    void append(int data){
        node *p = _head;
        if(_head == nullptr){
            prepend(data);
        }else{
             while (p->_next != nullptr) {
                 p = p->_next;
             }
             p->_next = new node(data);
            _tail = p->_next;
        }
    }
    
    void prepend(int data){
        node *temp = _head;
        if(_head == nullptr){
            _head = new node(data);
            _tail = _head;
        }else{
            _head = new node(data);
            _head->_next = temp;
        }
    }
    
    void remove(int data){
        node *p = _head;
        node *q = _head;
        while(p != nullptr){
            if(_head->_data == data){
                _head = _head->_next;
            }else if(p->_data == data){
                if(p->_next == nullptr){
                    _tail = q;
                }
                q->_next = p->_next;
            }
            q = p;
            p = p->_next;
        }
    }
    
    void traverse(){
           for(node *p = _head; p != nullptr; p = p->_next){
               if(p->_next != nullptr){
                   cout << p->_data << ", ";
               }else{
                   cout << p->_data;
               }
           }
           cout << endl;
       }
    
    int tail(){
        return _tail->_data;
    }
    
};

int main(int argc, const char * argv[]) {
    circular list;
    list.prepend(50);
    list.prepend(100);
    list.prepend(150);
    list.prepend(200);
    list.prepend(250);
    list.prepend(350);
    list.prepend(400);
    list.prepend(450);
    list.append(5);
    list.append(10);
    list.append(15);
    list.append(20);
    list.append(25);
    list.append(35);
    list.append(40);
    list.append(45);
    list.traverse();
    cout << list.tail() << endl;
    list.remove(45);
    list.traverse();
    cout << list.tail() << endl;
    return 0;
}
