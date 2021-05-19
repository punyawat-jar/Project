class Question{
    private:
        int Ans;

    public:
        virtual void ask(int);
        void answer(string);
        int get_ans();
};

class SubQ:public Question{
    private:
        string q[5]={   "Question 1: What is your level of confidence that the economy will recover in the next six months from any damage resulting from the coronavirus situation? ",
                        "Question 2: How do you assess the risk of serious harm to you or a loved one due to coronavirus at this point?",
                        "Question 3: How much do you trust the guidance from local officials on when it is safe to reopen/resume normal activities?",
                        "Question 4: What is your level of confidence towards covid-19 vaccine?",
                        "Question 5: About the pandemic management by government, how much scores will you give to the government?",
                    };
    public:
        void ask(int x);
};

