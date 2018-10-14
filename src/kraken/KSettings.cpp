#include "KSettings.h"

#include "../external/SimpleIni.h"

namespace krk
{
	const char* APP_SETTINGS_PATH = "./app_settings.ini";

	bool CreateDefaultSettings(KSettings& setting)
	{
		CSimpleIniA settingsIniLoader;
		settingsIniLoader.SetUnicode();

		settingsIniLoader.SetValue("General", "ActiveProject", "None");

		const SI_Error savingError = settingsIniLoader.SaveFile(APP_SETTINGS_PATH);	
		const bool couldSaveFile = (savingError != SI_FAIL || savingError != SI_NOMEM || savingError != SI_FILE);
		assert(couldSaveFile && "Could not save the default app settings INI file");
		
		return couldSaveFile;
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

		return true;
	}
}