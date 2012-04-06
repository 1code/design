//AbractionImp.h

#ifndef _ABSTRACTIONIMP_H_
#define _ABSTRACTIONIMP_H_

class WindowImp {
	public:
		virtual ~WindowImp();
		virtual void DrawText() = 0;
		virtual void DrawLine() = 0;
	protected:
		WindowImp();
};

class XWindowImp : public WindowImp {
	public:
		XWindowImp();
		~XWindowImp();
		virtual void DrawText();
		virtual void DrawLine();
};

class PMWindowImp : public WindowImp {
	public:
		PMWindowImp();
		~PMWindowImp();
		virtual void DrawText();
		virtual void DrawLine();
};

#endif//~_ABSTRACTION_H_
