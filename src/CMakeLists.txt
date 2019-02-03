cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

add_library(Containers
	STATIC
		Stack.h
		Stack.c
		Queue.h
		Queue.c
		List.h
		List.c
		Allocator.h
		Allocator.c
	)

install(
	TARGETS
		Containers
	ARCHIVE
		DESTINATION ${INSTALL_LIBDIR}
		COMPONENT lib
	RUNTIME
		DESTINATION ${INSTALL_BINDIR}
		COMPONENT bin
	LIBRARY
		DESTINATION ${INSTALL_LIBDIR}
		COMPONENT lib
	PUBLIC_HEADER
		DESTINATION ${INSTALL_INCLUDEDIR}/${PROJECT_NAME}
		COMPONENT dev
)
