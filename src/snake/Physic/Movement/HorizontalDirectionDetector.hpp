#ifndef HORIZONTALDIRECTIONDETECTOR_H
#define HORIZONTALDIRECTIONDETECTOR_H

#include <snake/Physic/Movement/ChangedDirectionDetector.hpp>
#include <snake/Physic/Movement/DirectionResponser.hpp>

namespace snake::physic {
    
    class HorizontalDirectionDetector : public ChangedDirectionDetector {
    public:
        HorizontalDirectionDetector(MoveAction movementAction);
        
        ~HorizontalDirectionDetector() = default;

        bool isDirectionChanged() const override;
    private:
        DirectionResponser responser;
    };

}

#endif /* HORIZONTALDIRECTIONDETECTOR_H */
