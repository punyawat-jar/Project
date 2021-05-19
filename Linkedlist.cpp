#include <iostream>
using namespace std;

#include "node.h"
#include "Linkedlist.h"

LL::LL(){
    hol = NULL;
    size = 0;
}

LL::~LL(){
    //cout << "Linkedlist has been destructed" << endl;
}

void LL::addNODE(NODE*& x){
    NODE* t=hol;
    if(hol==NULL){
        hol->insert(x);
        hol=x;
        //cout << "This is if " << endl;
    }
    else{
        //cout << "This is else " << endl;
        while(t->move_next()!=NULL){
            t=t->move_next();
        }
        t->insert(x);
    }
    //hol = x;
    size++;
    //cout << "addNode Successfully" << endl;
}


void LL::showLL(){
    NODE* t=hol;
    int i;
    for(i=0;i<size;i++){
        t->showinfo();
        t=t->move_next();
        if(t==NULL){
            break;
        }
    }
}

void LL::sort(){                    //Insertion Sort
    NODE *t1=hol,*t2;
    int id,ans;
    while(t1->move_next()!=NULL){
        t1 = t1->move_next();
        t2 = t1->move_prev();
        ans = t1->get_ans();
        if(ans < t2->get_ans()){
            while(t2->move_prev()!=NULL && ans < t2->get_ans())
            {
                t2 = t2->move_prev();
            }
            t1->connect();
            t1->connect(t2);
            if(ans < t2->get_ans()){
                hol = t1;
            }
        }

    }
}

void LL::stats()
{
  int mode;

  float med;
  int med_location;
  NODE *medPtr = hol;
  med_location = size/2;
  if(size%2==0) //set of even numbers
  {
    for(int i = 0 ; i < med_location - 1 ; i++)
    {
      medPtr = medPtr -> move_next();
    }
    med = medPtr->get_ans() + medPtr->move_next()->get_ans()/2;
  }
  else{ // set of odd numbers
    for(int i = 0 ; i < med_location ; i++)
    {
      medPtr = medPtr->move_next();
    }
    med = medPtr->get_ans();
  }
  cout << "Med : " << med << endl;

  float mean;
  int mean_location;
  NODE *meanPtr = hol;
  while(meanPtr->move_next()!=NULL)
  {
    mean += meanPtr->get_ans();
    meanPtr = meanPtr->move_next();
  }
  mean = mean/size;
  cout << "Mean : " << mean << endl;
}