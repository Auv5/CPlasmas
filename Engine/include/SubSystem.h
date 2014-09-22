#ifndef SUBSYSTEM_H_
#define SUBSYSTEM_H_
namespace Engine
{
	class SubSystem
	{
	public:
		SubSystem();
		virtual ~SubSystem();

		virtual void Init() = 0;

		virtual void Update() = 0;

		virtual const char *GetName() = 0;
	};
}

#endif
