//Abstraction.h

#ifndef _ABSTRACTION_H_
#define _ABSTRACTION_H_

class WindowImp;

class Window {
	public:
		virtual ~Window();
		virtual void DrawContents() = 0;
	protected:
		Window();
};

class IconWindow: public Window {
	public:
		IconWindow(WindowImp *imp);
		~IconWindow();
		void DrawContents();
	private:
		WindowImp* _imp;

};

class TransientWindow: public Window {
	public:
		TransientWindow(WindowImp *imp);
		~TransientWindow();
		void DrawContents();
	private:
		WindowImp* _imp;

};

#endif//~_ABSTRACTION_H_
