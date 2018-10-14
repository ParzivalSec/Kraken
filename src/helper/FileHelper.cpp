#include "FileHelper.h"

#include <QDir>
#include <QFileInfo>

namespace helper
{
	bool FileExists(const char* path)
	{
		QFileInfo file(path);
		return file.exists() && file.isFile();
	}

	void GetDirEntriesWithExtension(const QString& directory, const QString& extension, QVector<QString>& fileNames)
	{
		QDir dir(directory);
		dir.setNameFilters(QStringList(extension));
		dir.setFilter(QDir::Files | QDir::NoDotAndDotDot | QDir::NoSymLinks);

		const QStringList& dirEntryList = dir.entryList();
		fileNames.reserve(dirEntryList.size());

		for (const QString& dirEntry : dirEntryList)
		{
			fileNames.push_back(dirEntry);
		}
	}
}
