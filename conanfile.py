from pykuklin.conan.templates.AutotoolsTemplate import AutotoolsTemplate
from pykuklin.conan.tools import build_env_vars_set
from pykuklin.shellutils import shell

from conans import ConanFile, AutoToolsBuildEnvironment
from conans.client.conan_api import ConanAPIV1

import os

class ConanfileImpl(AutotoolsTemplate):
    name = "gnupg-kc"
    version = "2.2.20"
    requires = "gnupg-kc-common/2.2.20", "libgpg-error/1.39", "libgcrypt/1.8.6", "libassuan/2.5.3", "kc-common/0.1-SNAPSHOT"
    exports_sources = "*"
    generators = "pkg_config"

    def source(self):
        try:
            shell(['make', 'clean'])
        except AssertionError:
            pass # dont care

    def package(self):
        shell(['./autogen.sh'])
        with build_env_vars_set(self, append_libdirs_to_rpath = True):
            autotools = AutoToolsBuildEnvironment(self)
            autotools.configure(args=['--enable-maintainer-mode', '--with-common=' + self._get_libcommon_path()])
            autotools.make()
            autotools.install()

    def _get_libcommon_path(self):
        libcommon_pkgfolder = self.deps_cpp_info["gnupg-kc-common"].rootpath
        return os.path.realpath(libcommon_pkgfolder + "/lib/libcommon.a")
