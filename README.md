# GTestTemplate

**Generating GTest and GMock libs in QT Creator:**

1. Download googletest from git: https://github.com/google/googletest
2. Open googletest-master\googlemock\CMakeLists.txt on QT Creator and build using CMake
3. Right click the project and select rebuild.
4. Done. The lib libgtest.a will be waiting for you in the build folder. Copy them to your project's folder
5. In Qt, right click your project, select "Add Library...", External Library, select the libgtest.a and click ok.
6. Copy the googletest-master\googletest\include\gtest folder into your project folder
7. Now you can #include <gtest/gtest.h> and write your test cases
8. Repeat the same procedure for GMock