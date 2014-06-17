#ifndef GRAPHICS_H_
#define GRAPHICS_H_
namespace Engine
{
	class Graphics
	{
	public:
		static Graphics *Get();

	protected:
		Graphics();
		virtual ~Graphics();

	private:
		static Graphics *graphics;
	};
};

#endif