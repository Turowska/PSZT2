import os
import platform

if platform.system() == "Windows":
    print("Windows!")
    env = Environment() 
    #env.Append(CPPPATH = ['#include'])
    env.Append(LINKFLAGS='/SUBSYSTEM:CONSOLE') 
    env.Append(CXXFLAGS='/std:c++17')
    #VariantDir('#/bin', '#/src', duplicate=0)
    env.Program( 'projekt', Glob('*.cpp'))

else:
    print("Linux!")
    env = Environment() 
    #env.Append(CPPPATH = ['#include'])
    env.Append(CXXFLAGS='-std=c++17')
    #VariantDir('#/bin', '#/src', duplicate=0)
    env.Program( 'projekt', Glob('*.cpp'))
