#ifndef EBMSCORE_GLOBAL_H
#define EBMSCORE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(EBMSCORE_LIBRARY)
#  define EBMSCORESHARED_EXPORT Q_DECL_EXPORT
#else
#  define EBMSCORESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // EBMSCORE_GLOBAL_H