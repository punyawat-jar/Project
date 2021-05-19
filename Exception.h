class main_menu_exception:public exception{
    virtual const char* what() const throw(){
        return "Please enter 0 - 3 only";
    }
}MM_E;