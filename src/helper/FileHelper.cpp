#include "FileHelper.h"

#include <QFileInfo>

namespace helper
{
	inline bool FileExists(const char* path)
	{
		QFileInfo file(path);
		return file.exists() && file.isFile();
	}
}