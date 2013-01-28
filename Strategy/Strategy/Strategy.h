//Strategy.h

#ifndef _STRATEGY_H_
#define _STRATEGY_H_

class Compositor {
	public:
		Compositor();
		virtual ~Compositor();
		virtual void Compose() = 0;
};

class SimpleCompositor : public Compositor {
	public:
		SimpleCompositor();
		virtual ~SimpleCompositor();
		virtual void Compose();
};

class TexCompositor : public Compositor {
	public:
		TexCompositor();
		virtual ~TexCompositor();
		virtual void Compose();
};

class ArrayCompositor : public Compositor {
	public:
		ArrayCompositor();
		virtual ~ArrayCompositor();
		virtual void Compose();
};

#endif //~_STRATEGY_H_
