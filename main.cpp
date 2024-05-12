#include "mbed.h"

DigitalOut myled(LED1);
Serial pc(USBTX, USBRX); // Use correct pin names for USB serial port
Serial dev(PA_10, PA_9); // Use correct pin names for UART

void dev_recv() {
    while (dev.readable()) {
        pc.putc(dev.getc());
    }
}

void pc_recv() {
    while (pc.readable()) {
        dev.putc(pc.getc());
    }
}

int main() {
    pc.baud(9600);
    dev.baud(115200);
    pc.attach(&pc_recv);
    dev.attach(&dev_recv);
    pc.printf("Hello!! \r\n");

    while (1) {
        myled = 1;
        ThisThread::sleep_for(1000ms);
        myled = 0;
        ThisThread::sleep_for(1000ms);
    }
}
