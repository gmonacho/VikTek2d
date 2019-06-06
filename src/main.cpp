#include <iostream>
#include <VRA/Init.h>
#include <VRA/Window.h>
#include <VRA/Event.h>
#include <VRA/Renderer.h>

int		main()
{
	vra::Init(SDL_INIT_VIDEO, IMG_INIT_PNG);
	vra::Window 	window{"VikTek2d Main Test Program", 100, 100, 800, 600, SDL_WINDOW_SHOWN};
	vra::Renderer	renderer{window, true, 0};
	vra::Event		event{};
	bool			loop{true};

	while (loop)
	{
		renderer.setDrawColor(50, 50, 50, 255);
		renderer.clear();
		event.waitEvent();
		if (event.isKeyPressed(SDL_SCANCODE_ESCAPE) || event.getEvent().type == SDL_QUIT)
			loop = false;
		renderer.display();
	}
	std::cout << "Hello World !" << std::endl;
	return (1);
}