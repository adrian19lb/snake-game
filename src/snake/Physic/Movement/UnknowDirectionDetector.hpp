#ifndef UNKNOWDIRECTIONDETECTOR_H
#define UNKNOWDIRECTIONDETECTOR_H

#include <snake/Physic/Movement/ChangedDirectionDetector.hpp>
#include <snake/Physic/Movement/DirectionResponser.hpp>

namespace snake::physic {

    class UnknownDirectionDetector : public ChangedDirectionDetector {
    public:
        UnknownDirectionDetector(MoveAction movementAction);
        
        ~UnknownDirectionDetector() = default;

        bool isDirectionChanged() const override;
    private:
        DirectionResponser directionResponser;
    };

}

#endif /* UNKNOWDIRECTIONDETECTOR_H */
