//
// Created by renbin jiang on 2022/3/23.
//

#ifndef LEARNOPENGL_COMMON_H
#define LEARNOPENGL_COMMON_H

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <glm/glm.hpp>

#include <iostream>
#include <thread>
class Common {
public:
  Common() {}
  Common(GLFWwindow *window) : m_pWindow(window) {}
  void setWindow(GLFWwindow *window) {
    if (!window)
      return;
    m_pWindow = window;
  }
  void getWindow(GLFWwindow *window) {
    if (!m_pWindow)
      return;
    window = m_pWindow;
  }
  void getWindowSize(int &w, int &h) {
    if (!m_pWindow)
      return;
    glfwGetWindowSize(m_pWindow, &w, &h);
  }
  virtual ~Common() {
    if (m_sInstance) {
      delete m_sInstance;
      m_sInstance = nullptr;
    }
  }
  void getFramebufferSize(int *width, int *height) {
    if (!m_pWindow)
      return;
    glfwGetFramebufferSize(m_pWindow, width, height);
    //    std::cout << "glfwGetFramebufferSize w : " << *width << " h : " <<
    //    *height << std::endl;
  }
  void getFrameSize(int *left, int *top, int *right, int *bottom) {
    if (!m_pWindow)
      return;
    glfwGetWindowFrameSize(m_pWindow, left, top, right, bottom);
    std::cout << "Frame Size:[" << *left << "," << *top << "," << *right << ","
              << *bottom << "]" << std::endl;
  }
  float getWindowOpacity(void) {
    if (!m_pWindow)
      return 0;
    return glfwGetWindowOpacity(m_pWindow);
  }

  void setWindowOpacity(float opacity) {
    if (!m_pWindow)
      return;
    return glfwSetWindowOpacity(m_pWindow, opacity);
  }
  void restoreWindow(void) {
    if (!m_pWindow)
      return;
    // F12 restore widow size
    if (glfwGetKey(m_pWindow, GLFW_KEY_F12) == GLFW_PRESS) {
      std::cout << "restore Window" << std::endl;
      glfwRestoreWindow(m_pWindow);
    }
  }
  void setWindowMaximize(void) {
    if (!m_pWindow)
      return;
    glfwMaximizeWindow(m_pWindow);
  }

  void showWindow(void) {
    if (!m_pWindow)
      return;
    glfwShowWindow(m_pWindow);
  }

  void hideWindow(void) {
    if (!m_pWindow)
      return;
    glfwHideWindow(m_pWindow);
  }

  int getKeyStatus(int key) {
    if (!m_pWindow)
      return -1;
    return glfwGetKey(m_pWindow, key);
  }

  int getMouseButton(int button) {
    if (!m_pWindow) {
      return -1;
    }
    return glfwGetMouseButton(m_pWindow, button);
  }

  void setCursorPos(double xpos, double ypos) {
    if (!m_pWindow)
      return;
    glfwSetCursorPos(m_pWindow, xpos, ypos);
  }

  void getCursorPos(double &xpos, double &ypos) {
    if (!m_pWindow)
      return;
    glfwGetCursorPos(m_pWindow, &xpos, &ypos);
  }

  uint64_t getTimerFrequency(void) {
    if (!m_pWindow)
      return 0;
    return glfwGetTimerFrequency();
  }
  uint64_t getTimerValue(void) {
    if (!m_pWindow)
      return 0;
    return glfwGetTimerValue();
  }

  void setTime(double time) {
    if (!m_pWindow)
      return;
    glfwSetTime(time);
  }

  void setClipboardString(const char *string) {
    if (!m_pWindow)
      return;
    glfwSetClipboardString(m_pWindow, string);
  }

  const char *getClipboardString(void) {
    if (!m_pWindow)
      return nullptr;
    return glfwGetClipboardString(m_pWindow);
  }
  
  void processWindow(void) {
    if (!m_pWindow)
      return;
    int xPos, yPos;
    glfwGetWindowPos(m_pWindow, &xPos, &yPos);
    //  std::cout << "x = " <<  xPos << " y = " << yPos << std::endl;
    // A : left move m_pWindow
    // D : right move m_pWindow
    // S : down move m_pWindow
    // W : up move m_pWindow
    if (glfwGetKey(m_pWindow, GLFW_KEY_A) == GLFW_PRESS) {
      xPos -= 10;
      glfwSetWindowPos(m_pWindow, xPos, yPos);
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    if (glfwGetKey(m_pWindow, GLFW_KEY_D) == GLFW_PRESS) {
      xPos += 10;
      glfwSetWindowPos(m_pWindow, xPos, yPos);
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    if (glfwGetKey(m_pWindow, GLFW_KEY_S) == GLFW_PRESS) {
      yPos += 10;
      glfwSetWindowPos(m_pWindow, xPos, yPos);
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    if (glfwGetKey(m_pWindow, GLFW_KEY_W) == GLFW_PRESS) {
      yPos -= 10;
      glfwSetWindowPos(m_pWindow, xPos, yPos);
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    // resize m_pWindow size:
    // L : resize w
    // J : shrink w
    // I : resize h
    // K : shrink h
    int w, h;
    glfwGetWindowSize(m_pWindow, &w, &h);
    if (glfwGetKey(m_pWindow, GLFW_KEY_J) == GLFW_PRESS) {
      w -= 2;
      glfwSetWindowSize(m_pWindow, w, h);
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    if (glfwGetKey(m_pWindow, GLFW_KEY_L) == GLFW_PRESS) {
      w += 2;
      glfwSetWindowSize(m_pWindow, w, h);
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    if (glfwGetKey(m_pWindow, GLFW_KEY_K) == GLFW_PRESS) {
      h += 2;
      glfwSetWindowSize(m_pWindow, w, h);
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    if (glfwGetKey(m_pWindow, GLFW_KEY_I) == GLFW_PRESS) {
      h -= 2;
      glfwSetWindowSize(m_pWindow, w, h);
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    glfwGetKeyName(GLFW_KEY_W, 0);
  }

  void SetWindowPosCallback(void) {
    if (!m_pWindow || !m_sInstance)
      return;
    glfwSetWindowPosCallback(m_pWindow, this->set_window_pos_callback);
  }
  void setFramebufferSizeCallback(void) {
    if (!m_pWindow || !m_sInstance)
      return;
    glfwSetFramebufferSizeCallback(m_pWindow,
                                   this->set_framebuffer_size_callback);
  }

  static Common *getInstance() {
    if (!m_sInstance) {
      m_sInstance = new Common();
    }
    return m_sInstance;
  }

private:
  GLFWwindow *m_pWindow = nullptr;
  static Common *m_sInstance;
  static void set_framebuffer_size_callback(GLFWwindow *window, int width,
                                            int height) {
    // make sure the viewport matches the new window dimensions; note that width
    // and height will be significantly larger than specified on retina
    // displays.
    glViewport(0, 0, width, height);
    std::cout << "width:" << width << " height:" << height << std::endl;
  }
  static void set_window_pos_callback(GLFWwindow *window, int x, int y) {
    std::cout << "x : " << x << " y : " << y << std::endl;
  }
};
#endif // LEARNOPENGL_COMMON_H
