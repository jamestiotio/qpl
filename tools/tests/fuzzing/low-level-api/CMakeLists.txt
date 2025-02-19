# ==========================================================================
# Copyright (C) 2022 Intel Corporation
#
# SPDX-License-Identifier: MIT
# ==========================================================================

project(ll_fuzzing VERSION 1.0 LANGUAGES CXX)

file(GLOB CPP_FILES "*.cpp")
add_custom_target(ll_fuzzy_tests)
foreach (FILE ${CPP_FILES})
	foreach (QPL_EXECUTION_PATH hw sw)
		file(RELATIVE_PATH FILE_REL_PATH ${CMAKE_CURRENT_SOURCE_DIR} ${FILE})
		string(REPLACE ".cpp" "" TARGET_NAME "${FILE_REL_PATH}")
		set(TARGET_NAME "${TARGET_NAME}_${QPL_EXECUTION_PATH}")
		add_executable(${TARGET_NAME} ${FILE_REL_PATH})
		target_compile_options(${TARGET_NAME}
								PRIVATE $<$<STREQUAL:${QPL_EXECUTION_PATH},hw>:-DQPL_EXECUTION_PATH=qpl_path_hardware>
								PRIVATE $<$<STREQUAL:${QPL_EXECUTION_PATH},sw>:-DQPL_EXECUTION_PATH=qpl_path_software>)
		target_link_libraries(${TARGET_NAME} PRIVATE qpl)
		add_dependencies(ll_fuzzy_tests ${TARGET_NAME})
	endforeach()
endforeach()
