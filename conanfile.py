from pykuklin.conan.templates.AutotoolsTemplate import AutotoolsTemplate
from pykuklin.conan.tools import build_env_vars_set
from pykuklin.shellutils import shell

from conans import ConanFile, AutoToolsBuildEnvironment

import os

class ConanfileImpl(AutotoolsTemplate):
    name = "gnupg-kc"
    version = "2.2.20"
    requires = "kc-common/0.1-SNAPSHOT", "libgpg-error/1.39", "libgcrypt/1.8.6"
    exports_sources = "*"
        # "*.ac", "*.am", "*.awk", "*.m4", "*.in", "*.h", "*.c", "*.sh", "*.texi", "*.pem", "build-aux/*", "*.template", "*.po", \
        # "NEWS", "INSTALL", "README", "AUTHORS", "ChangeLog", "COPYING", "ABOUT-NLS", \
        # "tools/addgnupghome", "tools/applygnupgdefaults", "po/Makevars", "po/*.sin", "artwork/*", \
        # "doc/*.svg", "doc/*.fig", "doc/*.txt", "doc/FAQ", "doc/DETAILS", "doc/DCO", "doc/HACKING", "doc/KEYSERVER", "doc/examples/*", \
        # "doc/OpenPGP", "doc/TRANSLATE", "README", "**/README"

    generators = "pkg_config"

    def source(self):
        try:
            shell(['make', 'clean'])
        except AssertionError:
            pass # dont care

    def package(self):
        shell(['./autogen.sh'])
        with build_env_vars_set(self, append_libdirs_to_ld_library_path = True):
            autotools = AutoToolsBuildEnvironment(self)
            autotools.configure(args=['--enable-maintainer-mode'])
            autotools.make()
            autotools.install()