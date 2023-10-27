#include <assert.h>
#include <fcntl.h>
#include <gbm.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <GLES3/gl31.h>

#define SURFACE_WIDTH 1920
#define SURFACE_HEIGHT 1080

int32_t main(int32_t argc, char *argv[]) {
  bool res;

  /* Open render node for the GPU */
  int32_t fd = open("/dev/dri/renderD128", O_RDWR);
  assert(fd > 0);

  struct gbm_device *gbm = gbm_create_device(fd);
  assert(gbm != NULL);

  struct gbm_surface *gbmEglSurface =
      gbm_surface_create(gbm, SURFACE_WIDTH, SURFACE_HEIGHT,
                         GBM_FORMAT_ARGB8888, GBM_BO_USE_RENDERING);
  assert(gbmEglSurface != NULL);

  /* Setup EGL from the GBM device */
  EGLDisplay eglDisplay =
      eglGetPlatformDisplay(EGL_PLATFORM_GBM_MESA, gbm, NULL);
  assert(eglDisplay != NULL);

  res = eglInitialize(eglDisplay, NULL, NULL);
  assert(res);

  /* Check necessary extensions are supported */
  const char *eglExtensionString = eglQueryString(eglDisplay, EGL_EXTENSIONS);
  assert(strstr(eglExtensionString, "EGL_KHR_create_context") != NULL);
  assert(strstr(eglExtensionString, "EGL_KHR_surfaceless_context") != NULL);

  static const EGLint eglConfigAttributes[] = {
      EGL_RENDERABLE_TYPE, EGL_OPENGL_ES3_BIT_KHR, EGL_NONE};
  EGLConfig eglConfig;
  EGLint eglConfigCount;

  res = eglChooseConfig(eglDisplay, eglConfigAttributes, &eglConfig, 1,
                        &eglConfigCount);
  assert(res);

  res = eglBindAPI(EGL_OPENGL_ES_API);
  assert(res);

  static const EGLint eglContextAttributes[] = {EGL_CONTEXT_CLIENT_VERSION, 3,
                                                EGL_NONE};
  EGLContext eglContext = eglCreateContext(
      eglDisplay, eglConfig, EGL_NO_CONTEXT, eglContextAttributes);
  assert(eglContext != EGL_NO_CONTEXT);

  /* Fetch function definition for eglCreatePlatformWindowSurfaceEXT */
  PFNEGLCREATEPLATFORMWINDOWSURFACEEXTPROC eglCreatePlatformWindowSurfaceEXT =
      (PFNEGLCREATEPLATFORMWINDOWSURFACEEXTPROC)eglGetProcAddress(
          "eglCreatePlatformWindowSurfaceEXT");

  /* Create EGL Surface for rendering */
  EGLSurface eglSurface = eglCreatePlatformWindowSurfaceEXT(
      eglDisplay, eglConfig, gbmEglSurface, NULL);
  res = eglMakeCurrent(eglDisplay, eglSurface, eglSurface, eglContext);
  assert(res);

  /* Render solid color to framebuffer */
  glClearColor(0.85f, 0.1f, 0.30f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_DEPTH_TEST);
  glDisable(GL_BLEND);
  eglSwapBuffers(eglDisplay, eglSurface);
  glFlush();

  /* Free resources from GL, EGL and GBM */
  eglDestroyContext(eglDisplay, eglContext);
  eglTerminate(eglDisplay);
  gbm_device_destroy(gbm);
  close(fd);

  return 0;
}
