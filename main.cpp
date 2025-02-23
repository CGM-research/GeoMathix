#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

struct Color {
  float r, g, b, a;

};
Color bg; // Global background color

void OnResize(GLFWwindow* window, int width, int height) { // new width and height. Callback function
  glViewport(0, 0, width, height);
  //std::cout << "Window resized to " << width << "x" << height << '\n';
}

void processInput(GLFWwindow* window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, true);
    std::cout << "Escape key pressed" << '\n';
  }
  if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS) {
    bg = {1.f, 0.f, 0.f, 1.f};
  }
  if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS) {
    bg = {0.f, 1.f, 0.f, 1.f};
  }
  if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS) {
    bg = {0.f, 0.f, 1.f, 1.f};
  }
  if (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS) {
    bg = {0.f, 0.f, 0.f, 1.f};
  }
}

int32_t main() {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE,  GLFW_OPENGL_CORE_PROFILE);
  
  GLFWwindow* window = glfwCreateWindow(500, 500, "TestWindow", NULL, NULL);
  if (window == NULL) {
    std::cout << "Failed to create GLFW window" << '\n';
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD. Couldn't create window." << '\n';
    return -1;
  }

  glfwSetFramebufferSizeCallback(window, OnResize);

  glViewport(0, 0, 500, 500);
  
  while (!glfwWindowShouldClose(window)) {
    processInput(window);
    glClearColor(bg.r, bg.g, bg.b, bg.a);
    glClear(GL_COLOR_BUFFER_BIT);


    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}