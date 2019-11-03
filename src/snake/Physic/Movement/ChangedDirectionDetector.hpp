#ifndef CHANGEDDIRECTIONDETECTOR_H
#define CHANGEDDIRECTIONDETECTOR_H

namespace snake::physic {
    
    class ChangedDirectionDetector {
    public:    
        virtual bool isDirectionChanged() const = 0;
    };

}

#endif /* DIRECTIONDETECTOR_H */
