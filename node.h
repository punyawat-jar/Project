class NODE{
    private:
        int id,provi,A;
        NODE *next,*prev;
    public:
        NODE(int,int,int);
        NODE* move_next();
        NODE* move_prev();
        void insert(NODE*&);
        void showinfo();
        void connect();
        void connect(NODE*&);
        int get_id();
        int get_ans();
};
