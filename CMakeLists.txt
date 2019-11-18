add_library(property-macros INTERFACE)

cmake_policy(SET CMP0076 NEW)

target_sources(property-macros INTERFACE AutoPropertyHelpers.h ConstRefPropertyHelpers.h EnumClassHelper.h HelpersCommon.h ListPropertyHelper.h PropertyHelpers.h PtrPropertyHelpers.h SingletonHelper.h)
target_include_directories(property-macros INTERFACE ./)
