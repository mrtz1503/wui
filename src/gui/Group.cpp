#include "wui/gui/Group.h"

#include "wui/gui/Widget.h"

namespace wui {

    void Group::calcBoundingSize()
    {
        for each(Widget * widget  in m_children)
        {
            widget->calcBoundingSize();

            m_minWidth += widget->getMinWidth();
            m_maxWidth += widget->getMaxWidth();

            m_minHeight += widget->getMinHeight();
            m_maxHeight += widget->getMaxHeight();
        }
    }


}