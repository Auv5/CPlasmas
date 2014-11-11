#ifndef SELECTOR_H_
#define SELECTOR_H_

namespace Engine {
    class Graphics;
    class EventSystem;
    class Image;
    // class Sound;
    // class FileManager;
};

Engine::Graphics *SelectGfx();

Engine::EventSystem *SelectEvents();

Engine::Image *SelectImg(char *filename);

// Engine::Sound *SelectSound();

// Engine::FileManager *SelectFiles();


#endif
