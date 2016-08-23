#include <stdio.h>
#include <stdlib.h>
#include "mbed.h"
#include "rtos.h"
#include "mbed_mem_trace.h"

DigitalOut led1(LED1);

// main() runs in its own thread in the OS
// (note the calls to Thread::wait below for delays)
int main() {
    mbed_mem_trace_set_callback(mbed_mem_trace_default_callback);
    while (true) {
        void *p = malloc(50);
        led1 = !led1;
        Thread::wait(500);
        free(p);
    }
}

