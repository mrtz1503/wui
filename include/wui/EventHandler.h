#pragma once


#include <vector>
#include <memory>
#include <map>
#include <functional>

#include "wui/Event.h"

namespace wui {


    class EventHandlerFuncGeneric {
    public:

        virtual void operator()(Event&) = 0;

    };


    //template<typename Func>
    //class EventHandlerFunc : public EventHandlerFuncGeneric {

    //public:
    //    EventHandlerFunc(Func func) : m_func(func) {}
    //    void operator()(Event& event) override
    //    {
    //        m_func(event);
    //    }


    //private:
    //    Func m_func;

    //};


    template<typename Class, typename Params>
    class EventHandlerMethod : public EventHandlerFuncGeneric {
    public:

        EventHandlerMethod(Class* c, bool (Class::* f)(Params&)) : m_c(c), m_f(f) {};

        void operator()(Event& event) override
        {
            if (m_c)
            {
                (m_c->*m_f)(static_cast<Params&>(event));
            }
        }

    private:

        Class* m_c;
        bool(Class::* m_f)(Params&);
    };



    class EventHandler {
    public:

        template<typename Class, typename Params>
        void map(Event::Type type, Class* c, bool(Class::* f)(Params&))
        {
            EventHandlerMethod<Class, Params> handler(c, f);
            m_handlerFuncs.insert({ type, std::make_unique<EventHandlerMethod<Class, Params>>(c,f) });
        }


    private:
        std::multimap<Event::Type, std::unique_ptr<EventHandlerFuncGeneric>> m_handlerFuncs;
    };



}