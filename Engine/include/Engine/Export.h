#ifndef EXPORT_H
#define EXPORT_H

#pragma warning(disable : 4251)

#ifdef ENGINE_EXPORT
#define ENGINE_API __declspec(dllexport)
#else
#define ENGINE_API __declspec(dllimport)
#endif

#endif // EXPORT_H
