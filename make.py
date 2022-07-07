#!/usr/bin/env python3
#coding: utf-8

import licant
import licant.install
import os

licant.execute("astropathy.g.py")

CCFLAGS = '-fPIC -Werror=all -Werror=extra -pedantic-errors -Wreturn-type -g'
CXXFLAGS = CCFLAGS
LDFLAGS = '-g'

licant.cxx_library("shared",
	target="libastropathy.so",
	mdepends = ["astropathy"],
	cxx_flags = CXXFLAGS,
	cc_flags = CCFLAGS,
	ld_flags = LDFLAGS,
	shared = True,
	cxxstd = "c++17",
	ccstd = "c11",
	optimize = "-O3"
)

licant.install.install_library(
	tgt="install",
	uninstall="uninstall",
	libtgt="libigris.so",
	hroot="igris",
	headers="igris")

licant.ex("shared")
