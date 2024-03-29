/*******************************************************************************
 *
 * Benchmark Testing: Fibonacci Computation Using Recursion
 *
 * MIT License
 *
 * Copyright (c) 2021 Alvin Abad
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 ******************************************************************************/

#include <Arduino.h>
#include <SPI.h>

#define MAXLEN		1024
#define MAXSIZE		4096

unsigned long fib(unsigned int n);
void run();

// the setup function runs once when you press reset or power the board
void setup() {
    Serial.begin(115200);
    delay(2000);
    run();
}

void loop() {
    delay(1000);
}

void run() {
    Serial.println("Begin Fibonacci Benchmark.");

    unsigned long start, i, F;
    float diff;
    char buf[MAXLEN+1];

    start = millis();

    for (i=0; i<MAXSIZE; i++) {
        F = fib(i);
        diff = (float) (millis() - start);

        snprintf(buf, MAXLEN, "Fib(%2d) = %-10d, ", i, F);
        Serial.print(buf);

        Serial.print(diff/1000.0);
        Serial.println(" sec");
    }
}

unsigned long fib(unsigned int n) {
    if (n <= 1) {
        return n;
    }
    return fib(n-1) + fib(n-2);
}
