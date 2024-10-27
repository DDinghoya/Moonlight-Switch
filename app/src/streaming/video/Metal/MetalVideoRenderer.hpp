#pragma once
#if defined(PLATFORM_IOS)

#include "IVideoRenderer.hpp"
#include <SDL2/SDL.h>

class MetalVideoRenderer : public IVideoRenderer {
public:
    MetalVideoRenderer();
    ~MetalVideoRenderer();

    void waitToRender();
    void draw(NVGcontext* vg, int width, int height, AVFrame* frame) override;
    VideoRenderStats* video_render_stats() override;
private:
    void discardNextDrawable();
    bool updateColorSpaceForFrame(AVFrame* frame);
    bool updateVideoRegionSizeForFrame(AVFrame* frame);
    bool initialize();

    VideoRenderStats m_video_render_stats = {};
    SDL_Window* m_Window;
//    SDL_MetalView m_MetalView;

    int m_LastColorSpace = -1;
    bool m_LastFullRange = false;
    int m_LastFrameWidth = -1;
    int m_LastFrameHeight = -1;
    int m_LastDrawableWidth = -1;
    int m_LastDrawableHeight = -1;
};

#endif
