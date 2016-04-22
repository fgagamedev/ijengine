#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <list>

using std::list;

namespace ijengine {

    class Canvas;

    class GameObject {
    public:
        GameObject(GameObject *parent = nullptr, double x = 0.0, double y = 0.0);
        virtual ~GameObject();

        void add_children(GameObject *obj);
        void remove_children(GameObject *obj);

        double x() const;
        double y() const;

        virtual void update(int now, int last) {}
        // View
        virtual void draw(Canvas *canvas, int now, int last) {}

    protected:
        GameObject *m_parent;
        list<GameObject *> m_children;

        double m_x, m_y;
    };

}

#endif
