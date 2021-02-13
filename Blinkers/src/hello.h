#ifndef HELLO_H
#define HELLO_H

class Hello
{
    public:
        int number;
        void println();
        void println(char *s);
};

void Hello::println() {
    Serial.println("Hello, world");
}

void Hello::println(char *s) {
    Serial.println(s);
}

#endif
