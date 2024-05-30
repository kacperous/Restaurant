#include "model/Default.h"

double Default::getDiscount() const {
    return 0.0;
}

std::string Default::getTypeInfo() const {
    return "Default";
}

bool Default::vipTable() const {
    return false;
}