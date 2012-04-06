//Context.h

#ifndef _CONTEXT_H_
#define _CONTEXT_H_

class Compositor;

class Composition {
	public:
		Composition(Compositor* com);
		~Composition();
		void Repair();
	private:
		Compositor* _com;
};

#endif //~_CONTEXT_H_.
