#pragma once


#include <vector>
#include <memory>
#include <map>
#include <functional>

#include "wui/Event.h"

namespace wui {


	class EventHandlerFuncGeneric {

		virtual void operator()(Event&) = 0;
	};

	template<typename Func, typename Params>
	class EventHandlerFunc : EventHandlerFuncGeneric {

		EventHandlerFunc();
	};



	class EventHandler {
	public:

		template<typename EventType, typename Func>
		void map(Event::Type type, Func func>)
		{
			m_handlerFuncs.insert(type, std::make_unique<EventHandlerFunc<Func>>(func));
		}


	private:
		std::multimap<Event::Type, std::unique_ptr<EventHandlerFuncGeneric>> m_handlerFuncs;
	};



}