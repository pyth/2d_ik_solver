from conan import ConanFile
from conan.tools.cmake import CMake

class IKSolver(ConanFile):
    name = "ik_solver"
    version = "0.2.0"
    license = "MIT"
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps"

    def layout(self):
        self.folders.source = "src"
        self.folders.build = "build"

    def requirements(self):
        self.requires("sdl/2.30.9")
        self.requires("eigen/3.4.0")

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()