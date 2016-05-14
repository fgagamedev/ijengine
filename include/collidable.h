#ifndef IJENGINE_COLLIDABLE_H
#define IJENGINE_COLLIDABLE_H


#include <list>

using std::list;

namespace ijengine
{
    class Rectangle;

    class Collidable {
    public:
        virtual ~Collidable() = default;

        virtual bool active() const = 0;
        virtual const Rectangle& bounding_box() const = 0;
        virtual const list<Rectangle>& hit_boxes() const = 0;

        virtual void on_collision(const Collidable *who,
            const Rectangle& where) = 0;
    };
}

#endif 
