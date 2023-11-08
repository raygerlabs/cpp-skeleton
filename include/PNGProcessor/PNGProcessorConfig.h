#pragma once

#ifndef PNGPROCESSOR_DEBUG
#if defined _DEBUG
#define PNGPROCESSOR_DEBUG 1
#else
#define PNGPROCESSOR_DEBUG 0
#endif
#endif

#ifndef PNGPROCESSOR_DLL
#define PNGPROCESSOR_DLL 0
#endif

#ifndef PNGPROCESSOR_API
#if PNGPROCESSOR_DLL
#if defined _MSC_VER
#define PNGPROCESSOR_API __declspec(dllexport)
#define PNGPROCESSOR_LOCAL
#elif defined __GNUC__ && __GNUC__ >= 4
#define PNGPROCESSOR_API __attribute__((visibility("default")))
#define PNGPROCESSOR_LOCAL __attribute__((visibility("hidden")))
#else
#define PNGPROCESSOR_API
#define PNGPROCESSOR_LOCAL
#endif
#else
#define PNGPROCESSOR_API
#define PNGPROCESSOR_LOCAL
#endif
#endif
