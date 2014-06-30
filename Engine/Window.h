#ifndef WINDOW_H_
#define WINDOW_H_

#include "_BaseTypes.h"
#include "_ExportUtil.h"

extern struct Rect EXPORT USE_CURRENT_RESOLUTION;

namespace Engine
{
	class Entity;
};

using Engine::Entity;

namespace Engine
{
	class EXPORT Window
	{
	public:
		virtual void AddEntity(Entity *sprt, unsigned int z_index) = 0;
		virtual const Rect &GetPosition() = 0;
		virtual const Vec2D &GetSize() = 0;
		virtual bool IsFullscreen() = 0;
		virtual char *GetTitle() = 0;
		virtual void Update() = 0;
		virtual void SetBasicFillColor(ColorComp r, ColorComp g, ColorComp b, ColorComp a = 255) = 0;

		static const Rect USE_CURRENT_RESOLUTION;

	protected:
		Window();
		virtual ~Window();
	};
};
#endif