#ifndef ARENDERER_ARENDERER_H
#define ARENDERER_ARENDERER_H

#include "arenderer/Window.h"
#include "arenderer/context.h"

namespace arenderer {
	class ARenderer final{
	public:
		void Init(const std::string& name, int width, int heigh);
		void Run();

	private:
		void DrawFrame();
		Window window{};
		Context context{};
	};
}

#endif // !ARENDERER_ARENDERER_H