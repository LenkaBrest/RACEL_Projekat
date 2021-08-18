#ifndef DHT_GLOBAL_H
#define DHT_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(DHT_LIBRARY)
#  define DHTSHARED_EXPORT Q_DECL_EXPORT
#else
#  define DHTSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // DHT_GLOBAL_H
