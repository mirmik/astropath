#!/usr/bin/env python3

import sys
import licant
from licant.cxx_modules import application
from licant.modules import submodule, module
from licant.libs import include

licant.execute("../astropathy.g.py")

application("runtests",
	sources = [
		"*.cpp",
	],

	cxxstd="c++20",
	ccstd="c11",
	cxx_flags = "-g -Werror=all -Wno-gnu-zero-variadic-macro-arguments -Weffc++",
	cc_flags = "-g -Werror=all -Wno-gnu-zero-variadic-macro-arguments",

	include_paths = ["."],
	mdepends = ["astropathy"],

	libs = ["nos", "igris"]
)

licant.ex("runtests")
