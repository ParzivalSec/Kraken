#include "KSettings.h"

#include "../external/SimpleIni.h"

namespace
{
	const char* DEFAULT_PROJECT_FOLDER = "./";
}

namespace krk
{
	const char* APP_SETTINGS_PATH = "./app_settings.ini";

	KSettings CreateDefaultSettings(void)
	{
		CSimpleIniA settingsIniLoader;
		settingsIniLoader.SetUnicode();

		settingsIniLoader.SetValue("General", "ActiveProject", "None");
		settingsIniLoader.SetValue("General", "ProjectFolder", DEFAULT_PROJECT_FOLDER);

		const SI_Error savingError = settingsIniLoader.SaveFile(APP_SETTINGS_PATH);	
		const bool couldSaveFile = (savingError != SI_FAIL && savingError != SI_NOMEM && savingError != SI_FILE);
		assert(couldSaveFile && "Could not save the default app settings INI file");
		
		return KSettings
		{ 
			"None",
			DEFAULT_PROJECT_FOLDER
		};
	}

	bool LoadSettings(KSettings& settings)
	{
		CSimpleIniA settingsIniLoader;
		settingsIniLoader.SetUnicode();

		const SI_Error loadingError = settingsIniLoader.LoadFile(APP_SETTINGS_PATH);

		const bool errorDuringLoad = (loadingError == SI_FAIL || loadingError == SI_NOMEM || loadingError == SI_FILE);
		if (errorDuringLoad)
		{
			return false;
		}

		settings.activeProject = settingsIniLoader.GetValue("General", "ActiveProject", "None");
		settings.projectFolder = settingsIniLoader.GetValue("General", "ProjectFolder", DEFAULT_PROJECT_FOLDER);

		return true;
	}

	bool SaveSettings(const KSettings& settings)
	{
		CSimpleIniA settingsIniLoader;
		settingsIniLoader.SetUnicode();

		settingsIniLoader.SetValue("General", "ActiveProject", settings.activeProject.toUtf8().constData());
		settingsIniLoader.SetValue("General", "ProjectFolder", settings.projectFolder.toUtf8().constData());

		const SI_Error savingError = settingsIniLoader.SaveFile(APP_SETTINGS_PATH);
		const bool couldSaveFile = (savingError != SI_FAIL && savingError != SI_NOMEM && savingError != SI_FILE);
		assert(couldSaveFile && "Could not save the default app settings INI file");

		return couldSaveFile;
	}
}
