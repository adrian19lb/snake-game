#ifndef DIRECTION_H
#define DIRECTION_H

namespace snake::physic {
    
    class Direction {
    public:
       enum ID {
           Horizontal,
           Vertical,
           Unknown   
       };
    public:
       virtual ~Direction() = default;
       virtual ID getID() const = 0;
       bool operator==(Direction const& direction) const;
       bool operator!=(Direction const& direction) const;
    };

}
#endif /* DIRECTION_H */
