#include "printerqueue.h"

int main() {
    Printer<Job> printer;

    printer.addJob(Job(1, "Adrian", 5));
    printer.addJob(Job(2, "Carl", 12));
    printer.addJob(Job(3, "Bien", 3));
    printer.processAll();

    printer.addJob(Job(4, "Roy", 8));
    printer.addJob(Job(5, "Twain", 1));
    printer.processNext();
    printer.addJob(Job(6, "Eli", 20));
    printer.processAll();

    printer.processNext();

    return 0;
}