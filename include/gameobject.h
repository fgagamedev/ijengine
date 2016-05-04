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

        void update(unsigned now, unsigned last);
        void draw(Canvas *canvas, unsigned now, unsigned last);

    protected:
        GameObject *m_parent;
        list<GameObject *> m_children;

        double m_x, m_y;

        virtual void update_self(unsigned now, unsigned last) = 0;
        virtual void draw_self(Canvas *canvas, unsigned now, unsigned last) = 0;
    };

}

#endif
