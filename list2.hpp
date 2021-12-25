#pragma once
#include <iostream>

struct node {
    int element;
    node* next_node;
    node(int el, node* next = nullptr) 
        : element{el}, next_node{next} {};
};

class ourlist {
    public: 
        ourlist() = default;

        ourlist(std::initializer_list<int> l) {
            for(auto x : l){
                push_back(x);
            }
        }

        ourlist(const ourlist& temp){
            if(temp.empty()){
                head = nullptr;
                return;
            }
            auto t = temp.head;
            while(t!=nullptr){
                push_back(t->element);
                t=t->next_node;
            }
        }

        ourlist operator=(const ourlist& temp){
            auto t = temp.head;
            while(t!=nullptr){
                push_back(t->element);
                t=t->next_node;
            }
        }

        ~ourlist(){
            while(head -> next_node != nullptr ){
                auto temp = head;
                head = head->next_node;
                delete temp;
            }
            delete head;
            head = nullptr;
        }

        void erase(int el){
            if(empty()) return;

            if(head->element == el){
            auto temp = head;
            head = head -> next_node;
            delete temp;
            } else{
                auto temp = head;
                while(temp->next_node != nullptr && temp->next_node->element != el){
                    temp = temp->next_node;
                }
                auto to_delete = temp->next_node;
                if(to_delete != nullptr) {
                temp->next_node = temp->next_node->next_node;
                delete to_delete;
                }
            }
            --size;
        }

        void push_front(int el){
            auto new_node = new node(el, head);
            head = new_node;
        }

        void print() const {
            if( head==nullptr ){
                std::cout << "Empty list" << std::endl;
                return;
            }
            auto temp = head;
            while(temp != nullptr){
                std::cout << temp->element << ", ";
                temp = temp->next_node;
            }
            std::cout << "\b\b." << std::endl;
        }

        void push_back(int el){
            auto new_node = new node(el);

            if(empty()){
                head = new_node;
            } else{
                auto temp = head;
                while( temp->next_node != nullptr ) {
                    temp = temp->next_node;
                }
                temp->next_node = new_node;
            }
            ++size;
        }

        bool empty() const { return head == nullptr; }

    private:
        node* head{nullptr};
        int size = 0;
};