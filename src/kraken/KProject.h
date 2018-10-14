#ifndef _K_PROJECT_H_
#define _K_PROJECT_H_

#include <QString>

namespace krk
{
	struct KProject
	{
		QString name;
		QString path;
		// TODO: Add Commands list
		// TODO: Add Variables list
		// TODO: Add Categories list
	};

	KProject CreateNewProject(void);
	bool LoadProject(const char* path, KProject& project);
	bool SaveProject(const KProject& project);
	bool DeleteProject(const KProject& project);
}

#endif // _K_PROJECT_H_
