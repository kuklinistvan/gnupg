from pykuklin.conan.templates.AutotoolsTemplate import AutotoolsTemplate
from pykuklin.conan.tools import build_env_vars_set
from pykuklin.shellutils import shell, working_directory

from conans import ConanFile, AutoToolsBuildEnvironment

import os

class ConanfileImpl(AutotoolsTemplate):
    name = "gnupg-kc-common"
    version = "2.2.20"
    requires = "libgpg-error/1.39", "libgcrypt/1.8.6", "libassuan/2.5.3"
    exports_sources = "../*"
    generators = "pkg_config"

    def source(self):
        with working_directory(".."):
            try:
                shell(['make', 'clean'])
            except AssertionError:
                pass # dont care

    def package(self):
        shell(['./autogen.sh'])
        with build_env_vars_set(self, append_libdirs_to_rpath = True):
            autotools = AutoToolsBuildEnvironment(self)
            autotools.configure(args=['--enable-maintainer-mode'])
            with working_directory("common"):
                autotools.make()

        self.copy("common/libcommon.a", "lib", keep_path=False)
        self.copy("common/*.h", "include", keep_path=True)

    def package_info(self):
        self.cpp_info.libs = ["common"]