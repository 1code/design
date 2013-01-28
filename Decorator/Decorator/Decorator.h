//Decorator.h

#ifndef _DECORATOR_H_
#define _DECORATOR_H_

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
	protected:
	private:
};

class Decorator : public View {
	public:
		Decorator(View* view);
		virtual ~Decorator();
		virtual void Draw();
	protected:
		View* _view;
};

class ScrollDecorator : public Decorator {
	public:
		ScrollDecorator(View* view);
		~ScrollDecorator();
		virtual void Draw();
		void ScrollTo();
};

class BorderDecorator : public Decorator {
	public:
		BorderDecorator(View* view);
		~BorderDecorator();
		virtual void Draw();
		void DrawBorder();
};

#endif//~_DECORATOR_H_
