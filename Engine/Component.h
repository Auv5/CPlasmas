#ifndef COMPONENT_H_
#define COMPONENT_H_

namespace Engine
{
	class Entity;
};

using Engine::Entity;

class EXPORT GraphicalComponent
{
public:
	GraphicalComponent();
	virtual ~GraphicalComponent() {}
	
	virtual void DrawComponent(Entity* e) = 0;
};

class EXPORT LogicalComponent
{
public:
	LogicalComponent();
	virtual ~LogicalComponent() {}

	virtual void UpdateComponent(Entity* e) = 0;
};

class EXPORT HybridComponent : public GraphicalComponent, public LogicalComponent
{ 
public:
	HybridComponent();
	virtual ~HybridComponent() {}

	virtual void UpdateComponent(Entity *e) = 0;
	virtual void DrawComponent(Entity *e) = 0;
};

#endif