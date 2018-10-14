#include "KApplication.h"
#include "../helper/FileHelper.h"

namespace krk
{
	KApplication::KApplication() {}

	bool KApplication::Initialize()
	{
		if (helper::FileExists(APP_SETTINGS_PATH))
		{
			const bool loadedSettings = LoadSettings(mSettings);

			if (!loadedSettings)
				return false;
		}
		else
		{
			mSettings = CreateDefaultSettings();
		}

		const bool loadedAllProjects = LoadAllProjects();

#if _DEBUG
		for (const KProject& project : mProjects)
		{
			qDebug("Loaded [%s] from %s", qUtf8Printable(project.name), qUtf8Printable(project.path));
		}
#endif
		return loadedAllProjects;
	}

	void KApplication::Start()
	{
		// Show either editor, or populate the sys-tray menu
	}

	bool KApplication::LoadAllProjects()
	{
		QVector<QString> projectFileNames;
		helper::GetDirEntriesWithExtension(mSettings.projectFolder, "*.json", projectFileNames);

		mProjects.resize(projectFileNames.size());

		bool successfullyLoadedAllProjects = true;
		for (int idx = 0; idx < projectFileNames.size(); ++idx)
		{
			QString projectFilePath = mSettings.projectFolder + projectFileNames[idx];
			successfullyLoadedAllProjects = LoadProject(projectFilePath.toUtf8().constData(), mProjects[idx]);
			// TODO: Notify the user WHICH project could not be loaded
		}

		return successfullyLoadedAllProjects;
	}

	KApplication::~KApplication() {}
}
