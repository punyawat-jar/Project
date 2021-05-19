#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

#include "Question.h"
int PASS=1;

class YesNo_exception:public exception{
    virtual const char* what() const throw(){
        return "Please enter 0 or 1 only";
    }
}YN_E;

class Province_error:public exception{
    virtual const char* what() const throw(){
        return "Please enter 1-6 only";
    }
}Pro_E;

void Question::ask(int x){
    string Q[2] = { "What is your province?",
                    "Are you sure to submit the answer?"};
    do{
        PASS = 1;
        try{
            cout << Q[x] << endl;
            if(x==0){
                cout << "Your Province (1-6) : ";
                cin >> Ans;
                if(Ans<1||Ans>6||cin.fail()){
                   cin.clear();
                   cin.ignore(20,'\n');
                   throw Pro_E;
                }
            }
            else{
                cout << "Yes or No (1 or 0) : ";
                cin >> Ans;
                if(Ans<0 || Ans>1 || cin.fail()){
                   cin.clear();
                   cin.ignore(20,'\n');
                   throw YN_E;
                }
            }
        }
        catch(exception &e){
            PASS=0;
            cout << "=== ERROR : " << e.what() << " ===" << endl;
        }
    }while(PASS!=1);
}


void Question::answer(string q){
    do{
        PASS = 1;
        try{
            cout << "Your answer (1-5) : ";
            cin >> Ans;
            if(Ans<1||Ans>5||cin.fail()){
                cin.clear();
                cin.ignore(20,'\n');
                throw Pro_E;
            }
        }
        catch(exception &e){
            PASS=0;
            cout << "=== ERROR : " << e.what() << " ===" << endl;
            cout<< q << endl;
        }
    }while(PASS!=1);
}

int Question::get_ans(){
    return Ans;
}


void SubQ::ask(int x){
    cout << q[x] << endl;
    answer(q[x]);
    //cout << "Your answer is : " << get_ans() << endl;
}