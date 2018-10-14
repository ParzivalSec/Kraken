#include "FileHelper.h"

#include <QFileInfo>

namespace helper
{
	bool FileExists(const char* path)
	{
		QFileInfo file(path);
		return file.exists() && file.isFile();
	}
}