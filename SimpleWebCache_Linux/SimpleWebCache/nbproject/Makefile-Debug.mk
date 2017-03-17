#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/sources/FileCache.o \
	${OBJECTDIR}/sources/FileCacheItem.o \
	${OBJECTDIR}/sources/GarbageCollector.o \
	${OBJECTDIR}/sources/HTTPExceptionHandler.o \
	${OBJECTDIR}/sources/HTTPFormService.o \
	${OBJECTDIR}/sources/HTTPGETRequest.o \
	${OBJECTDIR}/sources/HTTPHTMLService.o \
	${OBJECTDIR}/sources/HTTPMethodNotAllowedExceptionHandler.o \
	${OBJECTDIR}/sources/HTTPNotAcceptableExceptionHandler.o \
	${OBJECTDIR}/sources/HTTPNotFoundExceptionHandler.o \
	${OBJECTDIR}/sources/HTTPPOSTRequest.o \
	${OBJECTDIR}/sources/HTTPRequest.o \
	${OBJECTDIR}/sources/HTTPRequestManager.o \
	${OBJECTDIR}/sources/HTTPResponseHeader.o \
	${OBJECTDIR}/sources/HTTPService.o \
	${OBJECTDIR}/sources/HTTPServiceManager.o \
	${OBJECTDIR}/sources/HTTPTransaction.o \
	${OBJECTDIR}/sources/TCPServerSocket.o \
	${OBJECTDIR}/sources/TCPSocket.o \
	${OBJECTDIR}/sources/Thread.o \
	${OBJECTDIR}/sources/UDPClientSocket.o \
	${OBJECTDIR}/sources/UDPServerSocket.o \
	${OBJECTDIR}/sources/UDPSocket.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-lpthread

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/simplewebcache

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/simplewebcache: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/simplewebcache ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iheaders -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/sources/FileCache.o: sources/FileCache.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iheaders -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/sources/FileCache.o sources/FileCache.cpp

${OBJECTDIR}/sources/FileCacheItem.o: sources/FileCacheItem.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iheaders -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/sources/FileCacheItem.o sources/FileCacheItem.cpp

${OBJECTDIR}/sources/GarbageCollector.o: sources/GarbageCollector.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iheaders -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/sources/GarbageCollector.o sources/GarbageCollector.cpp

${OBJECTDIR}/sources/HTTPExceptionHandler.o: sources/HTTPExceptionHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iheaders -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/sources/HTTPExceptionHandler.o sources/HTTPExceptionHandler.cpp

${OBJECTDIR}/sources/HTTPFormService.o: sources/HTTPFormService.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iheaders -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/sources/HTTPFormService.o sources/HTTPFormService.cpp

${OBJECTDIR}/sources/HTTPGETRequest.o: sources/HTTPGETRequest.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iheaders -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/sources/HTTPGETRequest.o sources/HTTPGETRequest.cpp

${OBJECTDIR}/sources/HTTPHTMLService.o: sources/HTTPHTMLService.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iheaders -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/sources/HTTPHTMLService.o sources/HTTPHTMLService.cpp

${OBJECTDIR}/sources/HTTPMethodNotAllowedExceptionHandler.o: sources/HTTPMethodNotAllowedExceptionHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iheaders -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/sources/HTTPMethodNotAllowedExceptionHandler.o sources/HTTPMethodNotAllowedExceptionHandler.cpp

${OBJECTDIR}/sources/HTTPNotAcceptableExceptionHandler.o: sources/HTTPNotAcceptableExceptionHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iheaders -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/sources/HTTPNotAcceptableExceptionHandler.o sources/HTTPNotAcceptableExceptionHandler.cpp

${OBJECTDIR}/sources/HTTPNotFoundExceptionHandler.o: sources/HTTPNotFoundExceptionHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iheaders -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/sources/HTTPNotFoundExceptionHandler.o sources/HTTPNotFoundExceptionHandler.cpp

${OBJECTDIR}/sources/HTTPPOSTRequest.o: sources/HTTPPOSTRequest.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iheaders -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/sources/HTTPPOSTRequest.o sources/HTTPPOSTRequest.cpp

${OBJECTDIR}/sources/HTTPRequest.o: sources/HTTPRequest.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iheaders -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/sources/HTTPRequest.o sources/HTTPRequest.cpp

${OBJECTDIR}/sources/HTTPRequestManager.o: sources/HTTPRequestManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iheaders -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/sources/HTTPRequestManager.o sources/HTTPRequestManager.cpp

${OBJECTDIR}/sources/HTTPResponseHeader.o: sources/HTTPResponseHeader.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iheaders -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/sources/HTTPResponseHeader.o sources/HTTPResponseHeader.cpp

${OBJECTDIR}/sources/HTTPService.o: sources/HTTPService.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iheaders -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/sources/HTTPService.o sources/HTTPService.cpp

${OBJECTDIR}/sources/HTTPServiceManager.o: sources/HTTPServiceManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iheaders -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/sources/HTTPServiceManager.o sources/HTTPServiceManager.cpp

${OBJECTDIR}/sources/HTTPTransaction.o: sources/HTTPTransaction.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iheaders -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/sources/HTTPTransaction.o sources/HTTPTransaction.cpp

${OBJECTDIR}/sources/TCPServerSocket.o: sources/TCPServerSocket.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iheaders -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/sources/TCPServerSocket.o sources/TCPServerSocket.cpp

${OBJECTDIR}/sources/TCPSocket.o: sources/TCPSocket.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iheaders -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/sources/TCPSocket.o sources/TCPSocket.cpp

${OBJECTDIR}/sources/Thread.o: sources/Thread.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iheaders -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/sources/Thread.o sources/Thread.cpp

${OBJECTDIR}/sources/UDPClientSocket.o: sources/UDPClientSocket.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iheaders -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/sources/UDPClientSocket.o sources/UDPClientSocket.cpp

${OBJECTDIR}/sources/UDPServerSocket.o: sources/UDPServerSocket.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iheaders -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/sources/UDPServerSocket.o sources/UDPServerSocket.cpp

${OBJECTDIR}/sources/UDPSocket.o: sources/UDPSocket.cpp 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iheaders -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/sources/UDPSocket.o sources/UDPSocket.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/simplewebcache

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
