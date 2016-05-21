#include "game_object.h"

#include <algorithm>

using std::stable_sort;

namespace ijengine {

    GameObject::GameObject(GameObject *obj, double xpos, double ypos,
        int p) : m_parent(obj), m_x(xpos), m_y(ypos),
        m_priority(p)
    {
        if (m_parent)
            m_parent->update_priorities();
    }

    GameObject::~GameObject()
    {
        for (auto obj : m_children)
            delete obj;
    }

    void
    GameObject::add_child(GameObject *obj)
    {
        if (obj != this)
            m_children.push_back(obj);

        update_priorities();
    }

    void
    GameObject::remove_child(GameObject *obj)
    {
        if (obj)
        {
            obj->set_parent(nullptr);
            m_children.erase(remove(m_children.begin(), m_children.end(), obj));
            update_priorities();
        }
    }

    void
    GameObject::update_priorities()
    {
        stable_sort(m_children.begin(), m_children.end(),
            [](GameObject *a, GameObject *b)
                { return a->priority() < b->priority(); }
        );
    }

    void
    GameObject::set_priority(int p)
    {
        if (p != m_priority)
        {
            m_priority = p;

            if (m_parent)
                m_parent->update_priorities();
        }
    }

    double
    GameObject::x() const
    {
        return m_x + (m_parent ? m_parent->x() : 0);
    }

    double
    GameObject::y() const
    {
        return m_y + (m_parent ? m_parent->y() : 0);
    }

    void
    GameObject::update(unsigned now, unsigned last)
    {
        for (auto child : m_children)
            child->update(now, last);

        update_self(now, last);
    }

    void
    GameObject::draw(Canvas *canvas, unsigned now, unsigned last)
    {
        draw_self(canvas, now, last);

        for (auto child : m_children)
            child->draw(canvas, now, last);
    }
} 
