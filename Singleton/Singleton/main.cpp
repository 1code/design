//main.cpp

#include "Singleton.h"

int main(int argc, char* argv[]) {
	Singleton* sgn = Singleton::instance();
	sgn->destroy();
	return 0;
}
