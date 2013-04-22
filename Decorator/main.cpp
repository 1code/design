#include "Decorator.h"

int main() {
    TextView textView;
    ScrollDecorator scrollDecorator(textView);
    BorderDecorator borderDecorator(scrollDecorator);
    borderDecorator.Draw();
    return 0;
}
