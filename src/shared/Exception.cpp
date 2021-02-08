#include "Exception.h"

using namespace std;
using namespace toast;

Exception::Exception(const char* msg) {
    this->msg = msg;
}

const char* Exception::what() const throw() {
    return msg;
}