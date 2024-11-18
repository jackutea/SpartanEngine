#ifndef ENGINE_DEFINE_H__
#define ENGINE_DEFINE_H__

#include <stdio.h>
#include "Exceptions/export.h"

#define SPARTAN_ENGINE

#define SPTAPI __declspec(dllexport)

// show line number and file name
#define SLog(...) printf("info: %s(%d): ", __FILE__, __LINE__); printf(__VA_ARGS__); printf("\r\n")
#define SLogWarn(...) printf("warn: %s(%d): ", __FILE__, __LINE__); printf(__VA_ARGS__); printf("\r\n")
#define SLogErr(...) printf("err: %s(%d): ", __FILE__, __LINE__); printf(__VA_ARGS__); printf("\r\n")

#endif // ENGINE_DEFINE_H__