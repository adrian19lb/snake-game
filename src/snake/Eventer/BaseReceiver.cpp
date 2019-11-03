#include <snake/Eventer/BaseReceiver.hpp>

namespace snake::eventer {
    BaseReceiver::BaseReceiver() {
        baseId = generateUniqueReceiverId();
    }
    unsigned BaseReceiver::getId() {
        return baseId;
    }
}
