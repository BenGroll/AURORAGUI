#pragma once

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <string>

class AuroraEngine {
    public: 
        AuroraEngine() {}
        ~AuroraEngine() {};

        // Returns 1 if there are any errors, else 0
        bool InitWindow();
        AuroraEngine* InitUI();
        AuroraEngine* withStyle();
        void Start();
        void Shutdown();
        void PreUpdate();
        void Update();
        void PostUpdate();
        void Render();

        GLFWwindow* getWindow() {
            return this->window;
        }
        void setWindow(GLFWwindow* windowToSet) {
            this->window = windowToSet;
        }

        int getWindowWidth() {
            return this->engineWindowWidth;
        }
        void setWindowWidth(int windowWidthToSet){
            this->engineWindowWidth = windowWidthToSet;
        }
        
        int getWindowHeight() {
            return this->engineWindowHeight;
        }
        void setWindowHeight(int windowHeightToSet) {
            this->engineWindowHeight = windowHeightToSet;
        }
         
        // string getGslsVersion() {
        //     return this->glsl_version;
        // }
        // void setGslsVersion(string glsl_versionToSet){
        //     this->glsl_version = glsl_versionToSet;
        // }

    private:
        GLFWwindow* window;
        int engineWindowWidth;
        int engineWindowHeight;
};
