#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include "_ExportUtil.h"
#include "_BaseTypes.h"

struct Vec2D;

namespace Engine
{
	class Window;
	class SubSystem;

	class ENGAPI Graphics
	{
	public:
		static Graphics *Get();

		virtual const char *GetIdentifier() = 0;

		virtual void Init() = 0;
		virtual void Start() = 0;

		virtual Window *NewWindow(const Rect& size, const char *title, bool fullscreen) = 0;
		virtual Window *NewWindow(double x, double y, const char *title, bool fullscreen) = 0;

		virtual void AddSubSystem(SubSystem *system) = 0;

		virtual Window *GetDefaultWindow() = 0;

		void RequestQuit();

	protected:
		Graphics();
		virtual ~Graphics();
		bool quit;

	private:
		static Graphics *graphics;
	};
}

#endif
