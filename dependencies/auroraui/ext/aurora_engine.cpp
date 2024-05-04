#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "aurora_engine.hpp"
#include <iostream>



// Returns 1 if there are any errors, else 0
bool AuroraEngine::InitWindow() {
    if (!glfwInit())
        return 1;
    // Decide GL+GLSL versions
    // GL 3.0 + GLSL 130
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only
    // Create window with graphics context
    GLFWwindow *window = glfwCreateWindow(1280, 720, "SAAS", NULL, NULL);
    if (window == NULL)
        return 1;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        throw("Unable to connect to OpenGL");

    int screen_width, screen_height;
    glfwGetFramebufferSize(window, &screen_width, &screen_height);
    glViewport(0, 0, screen_width, screen_height);
    AuroraEngine::setWindow(window);
    return 0;
}

AuroraEngine* AuroraEngine::InitUI() {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();

    ImGui_ImplGlfw_InitForOpenGL(this->window, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    return this;
}

AuroraEngine* AuroraEngine::withStyle() {
    ImGui::StyleColorsDark();
    return this;
};

void AuroraEngine::Start() {
    while(!glfwWindowShouldClose(AuroraEngine::getWindow())) {
        this->PreUpdate();
        this->Update();
        this->PostUpdate();
        this->Render();                
    }
    this->Shutdown();
}

void AuroraEngine::PreUpdate() {
    glfwPollEvents();
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
};

void AuroraEngine::Update() {
    // Insert Render Pipeline Here
    ImGui::Begin("SAAS");

    ImGui::Text("HI");

    ImGui::End();

    ImGui::Begin("SOOS");
    
    ImGui::Text("HI");

    ImGui::End();
};
void AuroraEngine::PostUpdate() {

}
void AuroraEngine::Render() {
    //Insert Render Pipeline here
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    glfwSwapBuffers(window);
}

void AuroraEngine::Shutdown() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
};
