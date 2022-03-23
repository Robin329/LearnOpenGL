#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <learnopengl/common.h>

#include <iostream>
#include <thread>

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

Common *Common::m_sInstance = nullptr;
Common *Instance = Common::getInstance();
int main() {
  // glfw: initialize and configure
  // ------------------------------
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

  // glfw window creation
  // --------------------
  GLFWwindow *window =
      glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
  if (window == NULL) {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }
  glfwSetWindowTitle(window, "LearnOpenGL");
  glfwMakeContextCurrent(window);
  //  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
  Common::getInstance()->setWindow(window);
  Instance->setFramebufferSizeCallback();
  //  glfwSetWindowPosCallback(window,
  //                           Common::getInstance()->set_window_pos_callback);
  Instance->SetWindowPosCallback();

  // glad: load all OpenGL function pointers
  // ---------------------------------------
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -1;
  }
  int major, minor, rev;
  glfwGetVersion(&major, &minor, &rev);
  const char *verStr = glfwGetVersionString();
  std::cout << "major:" << major << std::endl
            << "minor:" << minor << std::endl
            << "rev:" << rev << std::endl;
  std::cout << "verString:" << verStr << std::endl;
  int w, h;
  Common::getInstance()->getWindowSize(w, h);
  std::cout << "getWindowSize w : " << w << " h : " << h << std::endl;

  // render loop
  // -----------
  while (!glfwWindowShouldClose(window)) {
    // input
    // -----
    processInput(window);
    Instance->processWindow();
    //    Common::getInstance()->getFramebufferSize(&w, &h);
    //    int l,t,r,b;
    //    Common::getInstance()->getFrameSize(&l,&t,&r,&b);
    //    Common::getInstance()->restoreWindow();
    //    Instance->setClipboardString("Hello");
    //    std::cout << "ret : " << Instance->getClipboardString() << std::endl;

    // render
    // ------
    glClearColor(0.0f, 0.5f, 0.5f, 0.5f);
    glClear(GL_COLOR_BUFFER_BIT);

    // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved
    // etc.)
    // -------------------------------------------------------------------------------
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  // glfw: terminate, clearing all previously allocated GLFW resources.
  // ------------------------------------------------------------------
  glfwTerminate();
  return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this
// frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);
  //  Common::getInstance()->processWindow();
}

// glfw: whenever the window size changed (by OS or user resize) this callback
// function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
  // make sure the viewport matches the new window dimensions; note that width
  // and height will be significantly larger than specified on retina displays.
  glViewport(0, 0, width, height);
  std::cout << "width:" << width << " height:" << height << std::endl;
}