#ifndef BASERECEIVER_HPP_INCLUDED
#define BASERECEIVER_HPP_INCLUDED

#include <snake/Eventer/GeneratorId.hpp>

namespace snake::eventer {
    
    class BaseReceiver {
    public:
        BaseReceiver();
        virtual ~BaseReceiver() = default;
        unsigned getId();
    private:
        unsigned baseId;
    };

}
#endif // BASERECEIVER_HPP_INCLUDED
