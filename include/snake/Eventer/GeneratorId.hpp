#ifndef GENERATORID_HPP_INCLUDED
#define GENERATORID_HPP_INCLUDED

namespace snake::eventer {
    
    inline int generateUniqueReceiverId() noexcept {
        static int id = -1;
        return ++id;
    }
}


#endif // GENERATORID_HPP_INCLUDED
