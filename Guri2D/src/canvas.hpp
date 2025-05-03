#ifndef GURI2D_CANVAS_HPP
#define GURI2D_CANVAS_HPP

#include <string>
#include <memory>
#include <vector>
#include <functional>

namespace Guri2D {
    // Kanvas yöneticisi
    class CanvasManager {
    private:
        int width;
        int height;
        bool isFullscreen;
        bool isVisible;
        
        // Olay yöneticileri
        std::function<void(int, int)> onResize;
        std::function<void(bool)> onFullscreen;
        std::function<void(bool)> onVisibility;
        
    public:
        CanvasManager(int width = 800, int height = 600)
            : width(width), height(height), isFullscreen(false), isVisible(true) {}
        
        // Kanvas oluşturma
        void create() {
            // Kanvas oluşturma işlemleri
        }
        
        // Kanvas yükleme
        void load() {
            // Kanvas yükleme işlemleri
        }
        
        // Boyut yönetimi
        void setSize(int width, int height) {
            this->width = width;
            this->height = height;
            if (onResize) {
                onResize(width, height);
            }
        }
        
        void setFullscreen(bool fullscreen) {
            isFullscreen = fullscreen;
            if (onFullscreen) {
                onFullscreen(fullscreen);
            }
        }
        
        void setVisible(bool visible) {
            isVisible = visible;
            if (onVisibility) {
                onVisibility(visible);
            }
        }
        
        // Olay yöneticileri
        void onResize(const std::function<void(int, int)>& callback) {
            onResize = callback;
        }
        
        void onFullscreen(const std::function<void(bool)>& callback) {
            onFullscreen = callback;
        }
        
        void onVisibility(const std::function<void(bool)>& callback) {
            onVisibility = callback;
        }
        
        // Kanvas durumu
        int getWidth() const {
            return width;
        }
        
        int getHeight() const {
            return height;
        }
        
        bool isFullscreen() const {
            return isFullscreen;
        }
        
        bool isVisible() const {
            return isVisible;
        }
    };
    
    // Kanvas istemcisi
    class CanvasClient {
    private:
        std::shared_ptr<CanvasManager> manager;
        
    public:
        CanvasClient(std::shared_ptr<CanvasManager> manager)
            : manager(manager) {}
        
        void create() {
            manager->create();
        }
        
        void load() {
            manager->load();
        }
        
        void setSize(int width, int height) {
            manager->setSize(width, height);
        }
        
        void setFullscreen(bool fullscreen) {
            manager->setFullscreen(fullscreen);
        }
        
        void setVisible(bool visible) {
            manager->setVisible(visible);
        }
        
        void onResize(const std::function<void(int, int)>& callback) {
            manager->onResize(callback);
        }
        
        void onFullscreen(const std::function<void(bool)>& callback) {
            manager->onFullscreen(callback);
        }
        
        void onVisibility(const std::function<void(bool)>& callback) {
            manager->onVisibility(callback);
        }
        
        int getWidth() const {
            return manager->getWidth();
        }
        
        int getHeight() const {
            return manager->getHeight();
        }
        
        bool isFullscreen() const {
            return manager->isFullscreen();
        }
        
        bool isVisible() const {
            return manager->isVisible();
        }
    };
}

#endif // GURI2D_CANVAS_HPP
