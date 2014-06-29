#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include "_ExportUtil.h"
#include "_BaseTypes.h"

struct Vec2D;

namespace Engine
{
	class Window;
	class SubSystem;

	class EXPORT Graphics
	{
	public:
		static Graphics *Get();

		virtual char *GetIdentifier() = 0;

		virtual void Init() = 0;
		virtual void Start() = 0;

		virtual Window *NewWindow(Rect& size, char *title, bool fullscreen) = 0;
		virtual Window *NewWindow(float x, float y, char *title, bool fullscreen) = 0;

		virtual void AddSubSystem(SubSystem *system) = 0;

		virtual Window *GetDefaultWindow() = 0;

	protected:
		Graphics();
		virtual ~Graphics();

	private:
		static Graphics *graphics;
	};
};

#endif