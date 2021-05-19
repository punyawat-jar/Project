#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <exception>

using namespace std;

#include "interface.h"
#include "node.h"
#include "Linkedlist.h"
#include "Question.h"
#include "Exception.h"

void write_csv(string,int,int,int,int,int,int);
void read_csv();
void input_user();
void sort();
LL L[5];

int main(){
  int done=1,choice;
  read_csv();
  greeting();
  do{
    try{
      main_menu();
      cin >> choice;
      if(choice < 0||choice >3||cin.fail()){
        cin.clear();
        cin.ignore(20,'\n');
        throw MM_E;
      }
      switch(choice){
        case 0:
          ending();
          done = 1;
          break;
        case 1:
          input_user();
          break;
        case 2:
          sort();                       //sorting
          for(int i=0; i<5 ;i++){
            L[i].stats();               //stats
          }
          break;
      }
    }
    catch(exception &e){
      cout << "\t\t\t=== ERROR : " << e.what() << " ===" << endl;
      done= 0;
      clear_screen();
    }
  }while(done != 1);

  // read_csv();
  // input_user();
  //ending();
    
}


void write_csv(string file_name,int pro ,int a1,int a2,int a3, int a4,int a5){
    ifstream filer;
    ofstream filew;
    string id_s,pro_s,temp[5];
    NODE *t[5];
    int id=10001,data=0;

    filer.open(file_name,ios::in);
    filer.seekg(0,ios::end);
    data = filer.tellg();
    filer.close();
    filer.open(file_name);


    if(data==0||!filer.good()){
        filew.open(file_name);
        filew <<  id << "," << pro << "," << a1 << "," << a2 << "," << a3 << "," << a4 << "," << a5;
        filew.close();
    }
    else{
        while(filer.good()){             //Search for last id to +1
            getline(filer,id_s,',');
            getline(filer,temp[0],',');
            //cout << "The id_s is : " << id_s << endl;
            for(int i=0;i<=4;i++){
                if(i==4){
                    getline(filer,temp[i],'\n');
                }
                else{
                    getline(filer,temp[i],',');
                }
            }
        }
        id = stoi(id_s);
        filer.close();
        filew.open(file_name,ios_base::app);
        //cout << "The id is : " << id << ", The province is : " << pro << endl;
        filew << '\n' <<  ++id << "," << pro << "," << a1 << "," << a2 << "," << a3 << "," << a4 << "," << a5;
        filew.close();
    }
    t[0] = new NODE(id,pro,a1);
    t[1] = new NODE(id,pro,a2);
    t[2] = new NODE(id,pro,a3);
    t[3] = new NODE(id,pro,a4);
    t[4] = new NODE(id,pro,a5);

    for(int i=0;i<=4;i++){
        L[i].addNODE(t[i]);
    }
    for(int i=0 ;i<=4;i++){
        L[i].sort();
    }
    // cout<<"==================="<<endl;
    // L[0].showLL();
    // cout<<"==================="<<endl;
    // L[1].showLL();
    // cout<<"==================="<<endl;
    // L[2].showLL();
    // cout<<"==================="<<endl;
    // L[3].showLL();
    // cout<<"==================="<<endl;
    // L[4].showLL();
    // cout<<"=======END========="<<endl;
}



void input_user(){
    int a[5],pro,end;
    Question *Q;
    SubQ q[5],prov,YN;
    do{
        Q = &prov;
        Q->Question::ask(0);
        pro = Q->get_ans();
        for(int i=0;i<=4;i++){
            Q = &q[i];
            Q->ask(i);
            a[i] = Q->get_ans();
        }
        Q = &YN;
        Q->Question::ask(1);
        end = Q->get_ans();
    }while(end!=1);

    write_csv("Book1.csv",pro,a[0],a[1],a[2],a[3],a[4]);

}

void read_csv(){
    ifstream file;

    NODE* t[5];
    string id_s,pro_s,a[5];
    int id,pro,b[5];

    file.open("Book1.csv");

    while(file.good()){
        getline(file,id_s,',');
        id = stoi(id_s);
        getline(file,pro_s,',');
        pro = stoi(pro_s);
        for(int i=0;i<=4;i++){
            if(i==4){
                getline(file,a[i],'\n'); 
            }
            else{
                getline(file,a[i],',');
            }
        }
        //cout<< "The id_s : " <<id_s << endl;

        for(int i=0;i<=4;i++){
            b[i] = stoi(a[i]);
            t[i] = new NODE(id,pro,b[i]);
            L[i].addNODE(t[i]);
        }
    }
    
    sort();
    // for(int i=0 ;i<=4;i++){
    //     L[i].sort();
    // }
    // cout<<"==================="<<endl;
    // L[0].showLL();
    // cout<<"==================="<<endl;
    // L[1].showLL();
    // cout<<"==================="<<endl;
    // L[2].showLL();
    // cout<<"==================="<<endl;
    // L[3].showLL();
    // cout<<"==================="<<endl;
    // L[4].showLL();
    // cout<<"=======NOT END========="<<endl;
    file.close();
}

void sort(){
  for(int i=0 ;i<=4;i++){
        L[i].sort();
    }
}