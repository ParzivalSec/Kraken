#ifndef _FILE_HELPER_H_
#define _FILE_HELPER_H_
#include <QVector>

class QString;

namespace helper
{
	bool FileExists(const char* path);
	void GetDirEntriesWithExtension(const QString& directory, const QString& extension, QVector<QString>& fileNames);
}

#endif // _FILE_HELPER_H_
