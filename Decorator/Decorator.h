class View {
    public:
        virtual ~View();
        virtual void Draw();
    protected:
        View();
};

class TextView : public View {
    public:
        TextView();
        ~TextView();
        virtual void Draw();
};

class Decorator : public View {
    public:
        virtual ~Decorator();
        virtual void Draw();
    
    protected:
        Decorator(View & view);
    
    private:
        View & _view;
};

class ScrollDecorator : public Decorator {
    public:
        ScrollDecorator(View & view);
        ~ScrollDecorator();
        virtual void Draw();
        void ScrollTo();
};

class BorderDecorator : public Decorator {
    public:
        BorderDecorator(View & view);
        ~BorderDecorator();
        virtual void Draw();
        void SketchBorder();
};
