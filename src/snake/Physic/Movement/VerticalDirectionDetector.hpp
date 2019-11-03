#ifndef VERTICALDIRECTIONDETECTOR_H
#define VERTICALDIRECTIONDETECTOR_H

#include <snake/Physic/Movement/ChangedDirectionDetector.hpp>
#include <snake/Physic/Movement/DirectionResponser.hpp>

namespace snake::physic {
   
    class VerticalDirectionDetector : public ChangedDirectionDetector {
    public:
        VerticalDirectionDetector(MoveAction movementAction);
        
        ~VerticalDirectionDetector() = default;

        bool isDirectionChanged() const override;
    private:
        DirectionResponser responser;
    };


}

#endif /* VERTICALDIRECTIONDETECTOR_H */
