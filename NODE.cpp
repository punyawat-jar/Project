#include <iostream>
#include "node.h"
using namespace std;


NODE::NODE(int ID,int P,int ans){
    id = ID;
    A = ans;
    provi = P;
    //cout << "Node Created Successfully!" << endl;
}


NODE* NODE::move_next(){
    return next;
}

NODE* NODE::move_prev(){
    return prev;
}

void NODE::insert(NODE*& x){
    if(this==NULL){
        x->next = this;
        x->prev = this;
    }
    else{
        this->next = x;
        x->next = NULL;
        x->prev = this;
    }
}

void NODE::showinfo(){
    cout<< "ID: " << id << " Province : " << provi << " Ans: " << A << endl;
}

void NODE::connect(){
    NODE *st1, *st2;
    st1 = this->prev;
    st2 = this->next;
    st1->next = st2;
    if(st2!=NULL){
        st2->prev = st1;
    }
}

void NODE::connect(NODE*& x){
  NODE* t = x->next;
      if(this->get_ans() < x->get_ans()){
          this->prev = NULL;
          this->next = x;
          x->prev = this;
      }
      else{
          x->next  = this;
          this->prev = x;
          this -> next = t;
          t->prev = this;
      }
}

int NODE::get_id(){
    return id;
}

int NODE::get_ans(){
    return A;
}
