#ifndef _K_SETTINGS_H_
#define _K_SETTINGS_H_

#include <QString>

namespace krk
{
	extern const char* APP_SETTINGS_PATH;

	struct KSettings
	{
		QString activeProject;
		QString projectFolder;
	};

	KSettings CreateDefaultSettings(void);
	bool LoadSettings(KSettings& settings);
	bool SaveSettings(const KSettings& settings);
}

#endif // _K_SETTINGS_H_
