#include "model/VIP.h"

VIP::~VIP() {

}
std::string VIP::getTypeInfo() const {
    return "I'm Vip";
}
double VIP::getDiscount() const {
    return 0.85;
}
bool VIP::vipTable() const {
    return true;
}