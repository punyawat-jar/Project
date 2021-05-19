
void greeting()
{
  cout << "\t\t===============================" << endl;
  cout << "\t\t  Welcome to attitude tracker" <<endl;
  cout << "\t\t===============================" << endl;
  cout << "\t\t\tPress enter to continue" << endl;
  clear_screen();
}

void main_menu(){
  cout << "\t\t================================" << endl;
  cout << "\t\t\t\t\tMain Menu" << endl;
  cout << "\t\t\t1." << endl;
  cout << "\t\t\t2." << endl;
  cout << "\t\t\t3." << endl;
  cout << "\t\t\t0." << endl;
  cout << "\n" << "\t\tPlease select from 0-3 : ";
}

void ending()
{
  cout << "\t\t====================================" << endl;
  cout << "\t\t  Thank you for your kind response." <<endl;
  cout << "\t\t  Your response will be anonymous." <<endl;
  cout << "\t\t====================================" << endl;
}

void clear_screen(){
  getchar();
  system("clear");
}