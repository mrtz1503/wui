#pragma once

#include "wui/gui/Widget.h"
#include <vector>

namespace wui {

	class Group : public Widget {
	public:
		

		virtual void calcBoundingSize() override;


	private:
		std::vector<Widget*> m_children;
	};



}